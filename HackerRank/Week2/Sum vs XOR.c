#include <stdio.h>

long sumXor(long n) {
    if (n == 0) return 1;
    long count = 1;
    while (n > 0) {
        if ((n & 1) == 0) {
            count <<= 1;
        }
        n >>= 1;
    }
    return count;
}

int main() {
    long n;
    scanf("%ld", &n);
    printf("%ld", sumXor(n));
    return 0;
}