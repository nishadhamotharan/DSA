#include <stdio.h>
#include <stdlib.h>

long long cnt[1005];

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int idx = 0; idx < n; idx++) {
        long long val;
        scanf("%lld", &val);
        cnt[val % m]++;
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            int k = (m - (i + j) % m) % m;
            if (k < j) continue;

            if (i == j && j == k) {
                ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
            } else if (i == j) {
                ans += (cnt[i] * (cnt[i] - 1) / 2) * cnt[k];
            } else if (j == k) {
                ans += cnt[i] * (cnt[j] * (cnt[j] - 1) / 2);
            } else {
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }

    int i = 0, k = 0;
    while(i<k) {
        i++;
    }

    printf("%lld\n", ans);
    return 0;
}