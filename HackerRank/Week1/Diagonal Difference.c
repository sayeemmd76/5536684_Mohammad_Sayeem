#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int ltr = 0, rtl = 0;
    for (int i = 0; i < n; i++) {
        ltr += arr[i][i];
        rtl += arr[i][n - 1 - i];
    }
    int d = abs(ltr - rtl);
    printf("%d\n", d);
    return 0;
}