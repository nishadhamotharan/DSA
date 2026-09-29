#include <stdio.h>
#include <stdlib.h>
#define ll long long
typedef struct {
    ll l, r;
} Interval;
int compare(const void *a, const void *b) {
    Interval *i1 = (Interval *)a;
    Interval *i2 = (Interval *)b;
    if (i1->l != i2->l) {
        return (i1->l < i2->l) ? -1 : 1;
    }
    return (i1->r < i2->r) ? -1 : 1;
}
int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        ll n, k;
        if (scanf("%lld %lld", &n, &k) != 2) break;
        Interval intervals[1005];
        for (ll i = 0; i < n; i++) {
            scanf("%lld %lld", &intervals[i].l, &intervals[i].r);
        }
        qsort(intervals, n, sizeof(Interval), compare);
        ll cur_right = 0;
        ll maxright = 0;
        int i = 0;
        int possible = 1;
        while (cur_right < k) {
            maxright = cur_right;
            while (i < n && intervals[i].l <= cur_right + 1) {
                if (intervals[i].r > maxright) {
                    maxright = intervals[i].r;
                }
                i++;
            }
            if (cur_right == maxright) {
                possible = 0;
                break;
            }
            cur_right = maxright;
        }
        if (possible) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;  }
    