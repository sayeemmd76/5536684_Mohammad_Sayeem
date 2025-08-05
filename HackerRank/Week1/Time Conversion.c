#include <stdio.h>
#include <string.h>
int main() {
    char s[11];
    scanf("%s", s);
    int a = (s[0] - '0')*10 + (s[1] - '0');
    char ch = s[8];
    if (ch == 'P' && a != 12){
        a += 12;
    } 
    else if (ch == 'A' && a == 12){
        a = 0;
    }
    printf("%02d:%c%c:%c%c", a, s[3], s[4], s[6], s[7]);
    return 0;
}