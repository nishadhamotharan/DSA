#include <stdio.h>

#define MAXN 200005
#define INF 2000000000

int tree[4 * MAXN];
int a[MAXN];

int min(int x, int y) {
    return x < y ? x : y;
}
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        return INF;
    }
    if (l <= start && end <= r) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int left_min = query(2 * node, start, mid, l, r);
    int right_min = query(2 * node + 1, mid + 1, end, l, r);
    return min(left_min, right_min);
}
int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    build(1, 1, n);

    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(1, 1, n, l, r));
    }
    return 0;
}