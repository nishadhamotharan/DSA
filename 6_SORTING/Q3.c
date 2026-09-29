#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long long int x = *(const long long int *)a;
    long long int y = *(const long long int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;

    while (q--) {
        int n;
        if (scanf("%d", &n) != 1) break;
        long long row_sum[105] = {0};
        long long col_sum[105] = {0};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long val;
                scanf("%lld", &val);
                row_sum[i] += val;
                col_sum[j] += val;
            }
        }

        qsort(row_sum, n, sizeof(long long), compare);
        qsort(col_sum, n, sizeof(long long), compare);

        int possible = 1;
        for (int i = 0; i < n; i++) {
            if (row_sum[i] != col_sum[i]) {
                possible = 0;
                break;
            }
        }

        if (possible) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }

    return 0;
}