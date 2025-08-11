#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int maxMin(int k, int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    int min_diff = INT_MAX;
    for (int i = 0; i <= n - k; i++) {
        int diff = arr[i + k - 1] - arr[i];
        if (diff < min_diff) min_diff = diff;
    }
    return min_diff;
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    int *arr = malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("%d", maxMin(k, arr, n));
    free(arr);
    return 0;
}