#include <stdio.h>
#include <string.h>

char* balancedSums(int arr_count, int* arr) {
    int total = 0;
    for (int i = 0; i < arr_count; i++) {
        total += arr[i];
    }
    
    int left_sum = 0;
    for (int i = 0; i < arr_count; i++) {
        if (left_sum == total - left_sum - arr[i]) {
            return "YES";
        }
        left_sum += arr[i];
    }
    return "NO";
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("%s\n", balancedSums(n, arr));
    }
    return 0;
}