#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} DynamicArray;

int main() {
    int n, q, lastAnswer = 0;
    scanf("%d %d", &n, &q);
    
    DynamicArray* arr = calloc(n, sizeof(DynamicArray));
    int* answers = malloc(q * sizeof(int));
    int answer_count = 0;
    
    for (int i = 0; i < q; i++) {
        int type, x, y;
        scanf("%d %d %d", &type, &x, &y);
        int idx = (x ^ lastAnswer) % n;
        
        if (type == 1) {
            if (arr[idx].size == arr[idx].capacity) {
                arr[idx].capacity = arr[idx].capacity ? arr[idx].capacity * 2 : 1;
                arr[idx].data = realloc(arr[idx].data, arr[idx].capacity * sizeof(int));
            }
            arr[idx].data[arr[idx].size++] = y;
        } else {
            lastAnswer = arr[idx].data[y % arr[idx].size];
            answers[answer_count++] = lastAnswer;
        }
    }
    
    for (int i = 0; i < answer_count; i++) {
        printf("%d\n", answers[i]);
    }
    
    for (int i = 0; i < n; i++) {
        free(arr[i].data);
    }
    free(arr);
    free(answers);
    
    return 0;
}