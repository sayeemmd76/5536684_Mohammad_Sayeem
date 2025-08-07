#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); 
    int s[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    int d, m;
    scanf("%d %d", &d, &m);
    int count = 0;
    for (int i = 0; i <= n - m; i++) {
        int sum = 0;
        for (int j = i; j < i + m; j++) {
            sum += s[j];
        }
        if (sum == d) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}