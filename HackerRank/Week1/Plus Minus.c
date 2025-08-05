#include <stdio.h>
int main() {
    int a;
    scanf("%d", &a);
    int arr[a];
    int p = 0;
    int n = 0; 
    int z = 0;
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > 0){
            p++;
        }
        else if (arr[i] < 0){
            n++;
        }
        else{
            z++;
        }
    }
    printf("%.6f\n%.6f\n%.6f\n", (float)p/a, (float)n/a, (float)z/a);
    return 0;
}