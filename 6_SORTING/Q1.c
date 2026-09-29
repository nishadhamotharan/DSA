#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) break;

        int a[1000], b[1000];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &b[i]);
        }

        sort(a, n);
        sort(b, n);

        int count = 0;
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (b[j] >= a[i]) {
                count++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}