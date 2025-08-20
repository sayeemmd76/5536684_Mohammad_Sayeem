#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

void push(Stack* s, char c) {
    s->arr[++s->top] = c;
}

char pop(Stack* s) {
    return s->arr[s->top--];
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

char* isBalanced(char* s) {
    Stack stack;
    stack.top = -1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            push(&stack, s[i]);
        } else {
            if (isEmpty(&stack)) {
                return "NO";
            }
            char top = pop(&stack);
            if ((s[i] == '}' && top != '{') || 
                (s[i] == ']' && top != '[') || 
                (s[i] == ')' && top != '(')) {
                return "NO";
            }
        }
    }
    
    return isEmpty(&stack) ? "YES" : "NO";
}

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        char s[MAX_SIZE];
        scanf("%s", s);
        printf("%s\n", isBalanced(s));
    }
    
    return 0;
}