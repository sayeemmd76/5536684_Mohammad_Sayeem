#include <stdio.h>
#include <stdlib.h>

int* icecreamParlor(int m, int cost_count, int* cost, int* result_count) {
    int* result = malloc(2 * sizeof(int));
    *result_count = 2;
    
    for (int i = 0; i < cost_count - 1; i++) {
        for (int j = i + 1; j < cost_count; j++) {
            if (cost[i] + cost[j] == m) {
                result[0] = i + 1;
                result[1] = j + 1;
                return result;
            }
        }
    }
    
    return result;
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int m, n;
        scanf("%d", &m);
        scanf("%d", &n);
        
        int* cost = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            scanf("%d", &cost[i]);
        }
        
        int result_count;
        int* result = icecreamParlor(m, n, cost, &result_count);
        
        printf("%d %d\n", result[0], result[1]);
        
        free(cost);
        free(result);
    }
    
    return 0;
}