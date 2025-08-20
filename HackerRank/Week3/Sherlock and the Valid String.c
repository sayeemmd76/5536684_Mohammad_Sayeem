#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* isValid(char* s) {
    int freq[26] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        freq[s[i] - 'a']++;
    }

    int distinctFreq[26] = {0};
    int countInDistinct[26] = {0};
    int distinctCount = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            int found = 0;
            for (int j = 0; j < distinctCount; j++) {
                if (distinctFreq[j] == freq[i]) {
                    countInDistinct[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                distinctFreq[distinctCount] = freq[i];
                countInDistinct[distinctCount] = 1;
                distinctCount++;
            }
        }
    }

    if (distinctCount == 1) {
        return "YES";
    } else if (distinctCount == 2) {
        int minF = distinctFreq[0];
        int maxF = distinctFreq[0];
        for (int i = 1; i < distinctCount; i++) {
            if (distinctFreq[i] < minF) minF = distinctFreq[i];
            if (distinctFreq[i] > maxF) maxF = distinctFreq[i];
        }

        int count_minF = 0;
        int count_maxF = 0;
        for (int i = 0; i < distinctCount; i++) {
            if (distinctFreq[i] == minF) {
                count_minF = countInDistinct[i];
            }
            if (distinctFreq[i] == maxF) {
                count_maxF = countInDistinct[i];
            }
        }

        if ((maxF - minF == 1 && count_maxF == 1) || (minF == 1 && count_minF == 1)) {
            return "YES";
        } else {
            return "NO";
        }
    } else {
        return "NO";
    }
}

int main() {
    char s[100001];
    scanf("%s", s);
    char* result = isValid(s);
    printf("%s\n", result);
    return 0;
}