#include <stdio.h>
int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        unsigned int n;
        scanf("%u", &n);
        unsigned int a = ~n;
        printf("%u\n", a);
    }
    return 0;
}