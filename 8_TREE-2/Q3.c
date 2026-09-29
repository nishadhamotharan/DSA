#include <stdio.h>
#define MAXN 100005
int head[MAXN], to[2 * MAXN], next_edge[2 * MAXN], edge_cnt;
int tin[MAXN], low[MAXN], timer;
int bridge_u[MAXN], bridge_v[MAXN], bridge_cnt;
void add_edge(int u, int v) {
    edge_cnt++;
    to[edge_cnt] = v;
    next_edge[edge_cnt] = head[u];
    head[u] = edge_cnt;
}
void dfs(int u, int p) {
    timer++;
    tin[u] = low[u] = timer;
    for (int e = head[u]; e != 0; e = next_edge[e]) {
        int v = to[e];
        if (v == p) continue;
        if (tin[v]) {
            if (tin[v] < low[u]) low[u] = tin[v];
        } else {
            dfs(v, u);
            if (low[v] < low[u]) low[u] = low[v];
            if (low[v] > tin[u]) {
                bridge_cnt++;
                bridge_u[bridge_cnt] = u;
                bridge_v[bridge_cnt] = v;
            }
        }
    }
}
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++) {
        if (!tin[i]) {
            dfs(i, 0);
        }
    }
    printf("%d\n", bridge_cnt);
    for (int i = 1; i <= bridge_cnt; i++) {
        printf("%d %d\n", bridge_u[i], bridge_v[i]);
    }
    return 0;
}