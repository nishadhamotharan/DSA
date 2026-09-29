#include <stdio.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    for (int tc = 1; tc <= t; tc++) {
        int n, k, p;
        if (scanf("%d %d %d", &n, &k, &p) != 3) break;

        int dp[1505];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; i++) {
            int prefix[35];
            prefix[0] = 0;

            for (int j = 1; j <= k; j++) {
                int val;
                scanf("%d", &val);
                prefix[j] = prefix[j - 1] + val;
            }

            for (int j = p; j >= 0; j--) {
                for (int x = 1; x <= k && x <= j; x++) {
                    dp[j] = MAX(dp[j], dp[j - x] + prefix[x]);
                }
            }
        }

        printf("Case #%d: %d\n", tc, dp[p]);
    }

    return 0;
}