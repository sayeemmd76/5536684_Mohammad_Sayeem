#include <stdio.h>
#include <stdlib.h>

int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count) {
    int* unique_ranked = (int*)malloc(ranked_count * sizeof(int));
    int unique_count = 0;
    unique_ranked[unique_count++] = ranked[0];
    for (int i = 1; i < ranked_count; i++) {
        if (ranked[i] != unique_ranked[unique_count - 1]) {
            unique_ranked[unique_count++] = ranked[i];
        }
    }

    int* result = (int*)malloc(player_count * sizeof(int));
    *result_count = player_count;

    for (int i = 0; i < player_count; i++) {
        int score = player[i];
        int left = 0;
        int right = unique_count - 1;
        int rank = unique_count + 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (unique_ranked[mid] <= score) {
                rank = mid + 1;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        result[i] = rank;
    }

    free(unique_ranked);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int* ranked = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &ranked[i]);
    }

    int m;
    scanf("%d", &m);
    int* player = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        scanf("%d", &player[i]);
    }

    int result_count;
    int* result = climbingLeaderboard(n, ranked, m, player, &result_count);

    for (int i = 0; i < result_count; i++) {
        printf("%d\n", result[i]);
    }

    free(ranked);
    free(player);
    free(result);

    return 0;
}