#include <stdio.h>
#include <string.h>
#include <ctype.h>

long digitSum(const char *s) {
    long sum = 0;
    while (*s) {
        if (isdigit(*s)) {
            sum += *s - '0';
        }
        s++;
    }
    return sum;
}

long superDigit(long x) {
    if (x < 10) return x;
    long sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return superDigit(sum);
}

int main() {
    char n[100001];
    int k;
    scanf("%s %d", n, &k);
    
    long sum = digitSum(n) * k;
    printf("%ld", superDigit(sum));
    
    return 0;
}