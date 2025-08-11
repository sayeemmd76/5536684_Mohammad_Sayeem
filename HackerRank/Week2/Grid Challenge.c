#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sortString(char* s) {
    int count[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        count[s[i]-'a']++;
    }
    int pos = 0;
    for (int i = 0; i < 26; i++) {
        while (count[i]--) {
            s[pos++] = 'a' + i;
        }
    }
}

char* gridChallenge(int n, char** grid) {
    for (int i = 0; i < n; i++) {
        sortString(grid[i]);
    }
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            if (grid[i][j] < grid[i-1][j]) {
                return "NO";
            }
        }
    }
    return "YES";
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        char** grid = malloc(n * sizeof(char*));
        for (int i = 0; i < n; i++) {
            grid[i] = malloc((n+1) * sizeof(char));
            scanf("%s", grid[i]);
        }
        printf("%s\n", gridChallenge(n, grid));
        for (int i = 0; i < n; i++) {
            free(grid[i]);
        }
        free(grid);
    }
    return 0;
}