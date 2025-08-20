#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void detonate(char **grid, char **next, int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == 'O') {
                next[i][j] = '.';
                if (i > 0) next[i-1][j] = '.';
                if (i < r-1) next[i+1][j] = '.';
                if (j > 0) next[i][j-1] = '.';
                if (j < c-1) next[i][j+1] = '.';
            }
        }
    }
}

char **bomberMan(int n, int r, int c, char **grid) {
    if (n == 1) {
        char **result = malloc(r * sizeof(char *));
        for (int i = 0; i < r; i++) {
            result[i] = malloc(c + 1);
            strcpy(result[i], grid[i]);
        }
        return result;
    }

    if (n % 2 == 0) {
        char **result = malloc(r * sizeof(char *));
        for (int i = 0; i < r; i++) {
            result[i] = malloc(c + 1);
            for (int j = 0; j < c; j++) {
                result[i][j] = 'O';
            }
            result[i][c] = '\0';
        }
        return result;
    }

    char **state1 = malloc(r * sizeof(char *));
    char **state2 = malloc(r * sizeof(char *));
    for (int i = 0; i < r; i++) {
        state1[i] = malloc(c + 1);
        state2[i] = malloc(c + 1);
        for (int j = 0; j < c; j++) {
            state1[i][j] = 'O';
        }
        state1[i][c] = '\0';
    }

    detonate(grid, state1, r, c);

    if (n % 4 == 3) {
        for (int i = 0; i < r; i++) free(state2[i]);
        free(state2);
        return state1;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            state2[i][j] = 'O';
        }
        state2[i][c] = '\0';
    }

    detonate(state1, state2, r, c);

    for (int i = 0; i < r; i++) free(state1[i]);
    free(state1);

    return state2;
}

int main() {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    
    char **grid = malloc(r * sizeof(char *));
    for (int i = 0; i < r; i++) {
        grid[i] = malloc(c + 1);
        scanf("%s", grid[i]);
    }

    char **result = bomberMan(n, r, c, grid);
    for (int i = 0; i < r; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    for (int i = 0; i < r; i++) free(grid[i]);
    free(grid);
    return 0;
}