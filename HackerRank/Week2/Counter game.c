#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(unsigned long long n) {
    return (n & (n - 1)) == 0;
}

unsigned long long largestPower(unsigned long long n) {
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    return (n + 1) >> 1;
}

char* counterGame(unsigned long long n) {
    if (n == 1) return "Richard";
    int turn = 0;
    while (n != 1) {
        if (isPowerOfTwo(n)) {
            n /= 2;
        } else {
            n -= largestPower(n);
        }
        turn ^= 1;
    }
    return turn ? "Louise" : "Richard";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        unsigned long long n;
        scanf("%llu", &n);
        printf("%s\n", counterGame(n));
    }
    return 0;
}