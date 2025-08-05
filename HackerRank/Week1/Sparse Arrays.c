#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    char strings[n][100];
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }
    int q;
    scanf("%d", &q);
    char queries[q][100];
    for (int i = 0; i < q; i++) {
        scanf("%s", queries[i]);
    }
    int results[q];
    for (int i = 0; i < q; i++) {
        results[i] = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(queries[i], strings[j]) == 0) {
                results[i]++;
            }
        }
    }
    for (int i = 0; i < q; i++) {
        printf("%d\n", results[i]);
    }
    return 0;
}