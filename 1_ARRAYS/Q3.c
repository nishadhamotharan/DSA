#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n;
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        int found = 0;
        int start = -1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                if (start == -1) {
                    start = i - 1;
                }
            }
            else {
                if (start != -1) {
                    printf("(%d %d) ", start, i - 1);
                    found = 1;
                    start = -1;
                }
            }
        }
        if (start != -1) {
            printf("(%d %d)", start, n - 1);
            found = 1;
        }
        if (!found) {
            printf("No Profit");
        }
        printf("\n");
    }
    return 0;
}