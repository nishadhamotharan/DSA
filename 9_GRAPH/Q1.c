#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 1000000000000000LL

int n, m, k;
long long cost[25];

typedef struct {
    int u, v;
    int mask; 
} Edge;

Edge edges[1005];
int parent_ds[105];

int find_set(int v) {
    if (v == parent_ds[v])
        return v;
    return parent_ds[v] = find_set(parent_ds[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent_ds[b] = a;
    }
}
bool is_connected(int mask) {
    int i;
     for(i=1;i<=n;++i) {
        parent_ds[i] = i;
    }

    int components = n;
    for (i = 0; i < m; ++i) {
        if ((edges[i].mask & mask) == edges[i].mask) {
            if (find_set(edges[i].u) != find_set(edges[i].v)) {
                union_sets(edges[i].u, edges[i].v);
                components--;
            }
        }
    }
    return components == 1;
}
int main() {
    if (scanf("%d %d %d", &n, &m, &k) != 3) {
        return 0;
    }

    for (int i = 1; i <= k; ++i) {
        scanf("%lld", &cost[i]);
    }

    for (int i = 0; i < m; ++i) {
        int u, v, l;
        scanf("%d %d %d", &u, &v, &l);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].mask = 0;
        for (int j = 0; j < l; ++j) {
            int token_idx;
            scanf("%d", &token_idx);
            edges[i].mask |= (1 << (token_idx - 1));
        }
    }

    long long min_cost = INF;
    int total_masks = (1 << k);

    for (int mask = 0; mask < total_masks; ++mask) {
        long long current_cost = 0;
        for (int i = 1; i <= k; ++i) {
            if (mask & (1 << (i - 1))) {
                current_cost += cost[i];
            }
        }

        if (current_cost >= min_cost) continue;

        if (is_connected(mask)) {
            min_cost = current_cost;
        }
    }

    if (min_cost == INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", min_cost);
    }

    return 0;
}