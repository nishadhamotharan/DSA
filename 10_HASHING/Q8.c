#include <stdio.h>

#define MAXN 1000005

int a[MAXN];

int main() {
    int n, q, type, x, i;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    while (q--) {
        scanf("%d %d", &type, &x);
        if (type == 1) {
            a[x] = 1;
        } else {
            int ans = -1;
            for(i=x;i<=n;i++) {
                if (a[i] == 1) {
                    ans = i;
                    break;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}