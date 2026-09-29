#include <stdio.h>

void sort(int a[],int n) {
    int i, j, temp;
    for(i=0;i<n-1;i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n, k;
        if (scanf("%d %d", &n, &k) != 2) break;

        int a[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        sort(a, n);

        if (k > n || k <= 0) {
            printf("-1\n");
        } else {
            printf("%d\n", a[k - 1]);
        }
    }

    return 0;
}