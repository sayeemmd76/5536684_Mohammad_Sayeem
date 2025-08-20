#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    int length;
    int capacity;
} String;

typedef struct {
    String* states;
    int top;
    int capacity;
} HistoryStack;

String createString() {
    String s;
    s.capacity = 16;
    s.length = 0;
    s.data = malloc(s.capacity);
    s.data[0] = '\0';
    return s;
}

void appendToString(String* s, const char* w) {
    int wlen = strlen(w);
    if (s->length + wlen + 1 > s->capacity) {
        while (s->capacity <= s->length + wlen) {
            s->capacity *= 2;
        }
        s->data = realloc(s->data, s->capacity);
    }
    strcat(s->data, w);
    s->length += wlen;
}

void deleteFromString(String* s, int k) {
    if (k > s->length) k = s->length;
    s->length -= k;
    s->data[s->length] = '\0';
}

HistoryStack createHistoryStack() {
    HistoryStack stack;
    stack.capacity = 16;
    stack.top = -1;
    stack.states = malloc(stack.capacity * sizeof(String));
    return stack;
}

void pushHistory(HistoryStack* stack, String s) {
    if (stack->top == stack->capacity - 1) {
        stack->capacity *= 2;
        stack->states = realloc(stack->states, stack->capacity * sizeof(String));
    }
    stack->top++;
    stack->states[stack->top].data = malloc(s.length + 1);
    strcpy(stack->states[stack->top].data, s.data);
    stack->states[stack->top].length = s.length;
    stack->states[stack->top].capacity = s.length + 1;
}

String popHistory(HistoryStack* stack) {
    String state = stack->states[stack->top];
    stack->top--;
    return state;
}

int main() {
    int Q;
    scanf("%d\n", &Q);

    String S = createString();
    HistoryStack history = createHistoryStack();
    pushHistory(&history, S);

    while (Q--) {
        char line[1000002];
        fgets(line, sizeof(line), stdin);
        int t = line[0] - '0';

        if (t == 1) {
            char* w = strchr(line, ' ') + 1;
            w[strlen(w) - 1] = '\0';
            pushHistory(&history, S);
            appendToString(&S, w);
        } else if (t == 2) {
            int k = atoi(line + 2);
            pushHistory(&history, S);
            deleteFromString(&S, k);
        } else if (t == 3) {
            int k = atoi(line + 2);
            if (k > 0 && k <= S.length) {
                printf("%c\n", S.data[k - 1]);
            }
        } else if (t == 4) {
            free(S.data);
            S = popHistory(&history);
        }
    }

    free(S.data);
    for (int i = 0; i <= history.top; i++) {
        free(history.states[i].data);
    }
    free(history.states);

    return 0;
}