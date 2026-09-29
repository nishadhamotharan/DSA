#include <stdio.h>
#define MAXN 200005
long long tree[4 * MAXN];
long long a[MAXN];
void build(int k,int l,int r) {
    if (l == r) {
        tree[k] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    tree[k] = tree[2 * k] + tree[2 * k + 1];
}
void update(int k, int l, int r, int idx, long long val) {
    if (l == r) {
        tree[k] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (idx <= mid) {
        update(2 * k, l, mid, idx, val);
    } else {
        update(2 * k + 1, mid + 1, r, idx, val);
    }
    tree[k] = tree[2 * k] + tree[2 * k + 1];
}
long long query(int k, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[k];
    }
    int mid = (l + r) / 2;
    long long sum = 0;
    if (ql <= mid) {
        sum += query(2 * k, l, mid, ql, qr);
    }
    if (qr > mid) {
        sum += query(2 * k + 1, mid + 1, r, ql, qr);
    }
    return sum;
}
int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    while (q--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int idx;
            long long val;
            scanf("%d %lld", &idx, &val);
            update(1, 1, n, idx, val);
        } else {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%lld\n", query(1, 1, n, l, r));
        }
    }
    return 0;
}