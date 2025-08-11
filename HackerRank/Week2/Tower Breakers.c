#include <stdio.h>

int towerBreakers(int n, int m) {
    return (m == 1 || n % 2 == 0) ? 2 : 1;
}

int main() {
    int t, n, m;
    scanf("%d", &t);
    
    while (t--) {
        scanf("%d %d", &n, &m);
        printf("%d\n", towerBreakers(n, m));
    }
    
    return 0;
}