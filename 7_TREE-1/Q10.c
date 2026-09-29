#include <stdio.h>
#define MAXN 200005
int bit[MAXN];
long long a[MAXN];
int n;
void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] += val;
    }
}
int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}
int find_kth(int k) {
    int low = 1, high = n, ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (query(mid) >= k) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        update(i, 1);
    }
    for (int i = 1; i <= n; i++) {
        int p;
        scanf("%d", &p);
        int original_idx = find_kth(p);
        printf("%lld", a[original_idx]);
        if (i < n) {
            printf(" ");
        }
        update(original_idx, -1);
    }
    printf("\n");

    return 0;
}