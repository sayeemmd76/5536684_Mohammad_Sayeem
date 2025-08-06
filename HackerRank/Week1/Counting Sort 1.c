#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int farr[100] = {0};
    for (int i = 0; i < n; i++) {
        farr[arr[i]]++;
    }
    for (int i = 0; i < 100; i++) {
        printf("%d ", farr[i]);
    }
    return 0;
}