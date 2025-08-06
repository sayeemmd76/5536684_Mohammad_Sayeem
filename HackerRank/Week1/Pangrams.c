#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main() {
    char s[1000];
    fgets(s, sizeof(s), stdin);
    int l[26] = {0};
    for (int i = 0; i < strlen(s); i++) {
        char c = tolower(s[i]);
        if (c >= 'a' && c <= 'z') {
            l[c - 'a'] = 1;
        }
    }
    int is_pangram = 1;
    for (int i = 0; i < 26; i++) {
        if (l[i] == 0) {
            is_pangram = 0;
            break;
        }
    }
    printf("%s\n", is_pangram ? "pangram" : "not pangram");
    return 0;
}