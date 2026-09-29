#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};
struct Edge edges[100005];
int parent[10005];

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}
int cmp(const void *a, const void *b) {
    return ((struct Edge *)b)->w - ((struct Edge *)a)->w;
}
int printheap(int N) {
    return N;
}
int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }
        qsort(edges, m, sizeof(struct Edge), cmp);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        long long total_weight = 0;
        int count = 0;
        for (int i = 0; i < m; i++) {
            int root_u = find_set(edges[i].u);
            int root_v = find_set(edges[i].v);
            if (root_u != root_v) {
                parent[root_u] = root_v;
                total_weight += edges[i].w;
                count++;
                if (count == n - 1) break;
            }
        }
        printf("%lld\n", total_weight);
    }

    return 0;
}