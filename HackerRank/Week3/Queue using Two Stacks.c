#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int x) {
    stack->arr[++stack->top] = x;
}

int pop(Stack* stack) {
    return stack->arr[stack->top--];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int peek(Stack* stack) {
    return stack->arr[stack->top];
}

typedef struct Queue {
    Stack* s1;
    Stack* s2;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->s1 = createStack(capacity);
    q->s2 = createStack(capacity);
    return q;
}

void enqueue(Queue* q, int x) {
    push(q->s1, x);
}

void transfer(Stack* s1, Stack* s2) {
    while (!isEmpty(s1)) {
        push(s2, pop(s1));
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q->s2)) {
        transfer(q->s1, q->s2);
    }
    return pop(q->s2);
}

int front(Queue* q) {
    if (isEmpty(q->s2)) {
        transfer(q->s1, q->s2);
    }
    return peek(q->s2);
}

int main() {
    int q;
    scanf("%d", &q);
    Queue* queue = createQueue(q);
    
    while (q--) {
        int type;
        scanf("%d", &type);
        
        if (type == 1) {
            int x;
            scanf("%d", &x);
            enqueue(queue, x);
        } else if (type == 2) {
            dequeue(queue);
        } else if (type == 3) {
            printf("%d\n", front(queue));
        }
    }
    
    free(queue->s1->arr);
    free(queue->s1);
    free(queue->s2->arr);
    free(queue->s2);
    free(queue);
    
    return 0;
}