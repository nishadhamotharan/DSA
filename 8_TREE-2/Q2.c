#include <stdio.h>

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    int a[1005], i;
    for(i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    for (int j = n - 1; j >= 0; j--) {
        int left = 2 * j + 1;
        int right = 2 * j + 2;
        int mx = 0;
        if (left < n && a[left] > mx) mx = a[left];
        if (right < n && a[right] > mx) mx = a[right];
        a[j] += mx;
    }

    while (q--) {
        int idx;
        scanf("%d", &idx);
        printf("%d\n", a[idx - 1]);
    }

    return 0;
}