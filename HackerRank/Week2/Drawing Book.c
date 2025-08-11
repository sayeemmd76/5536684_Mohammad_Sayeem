#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int pageCount(int n, int p) {
    int from_front = p / 2;
    int from_back = (n / 2) - (p / 2);
    return min(from_front, from_back);
}

int main() {
    int n, p;
    scanf("%d", &n);
    scanf("%d", &p);
    printf("%d", pageCount(n, p));
    return 0;
}