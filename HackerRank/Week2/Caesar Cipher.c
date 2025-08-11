#include <stdio.h>
#include <ctype.h>
#include <string.h>

void caesarCipher(char* s, int k) {
    k %= 26;
    for (int i = 0; s[i]; i++) {
        if (isupper(s[i])) {
            s[i] = 'A' + (s[i] - 'A' + k) % 26;
        } else if (islower(s[i])) {
            s[i] = 'a' + (s[i] - 'a' + k) % 26;
        }
    }
}

int main() {
    int n, k;
    char s[101];
    
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &k);
    
    caesarCipher(s, k);
    printf("%s", s);
    
    return 0;
}