#include <stdio.h>

#define N 100005
#define M 200005

int head[N], to[2 * M], nxt[2 * M], id[2 * M], e_cnt = 1;
int dfn[N], low[N], timer;
int is_bridge[M], u_e[M], v_e[M], t_e[M];
int col[N], c_cnt;

void add(int u, int v, int idx) {
    to[++e_cnt] = v; id[e_cnt] = idx; nxt[e_cnt] = head[u]; head[u] = e_cnt;
}

int dfs1(int np,int lst) {
    dfn[np] = low[np] = ++timer;
    for (int e = head[np]; e; e = nxt[e]) {
        int v = to[e], i = id[e];
        if (i == lst) continue;
        if (dfn[v]) {
            if (dfn[v] < low[np]) low[np] = dfn[v];
        } else {
            dfs1(v, i);
            if (low[v] < low[np]) low[np] = low[v];
            if (low[v] > dfn[np]) is_bridge[i] = 1;
        }
    }
    return 0;
}
void dfs2(int u, int c) {
    col[u] = c;
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e], i = id[e];
        if (!col[v] && !is_bridge[i]) dfs2(v, c);
    }
}
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u_e[i], &v_e[i], &t_e[i]);
        add(u_e[i], v_e[i], i);
        add(v_e[i], u_e[i], i);
    }

    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs1(i, 0);

    for (int i = 1; i <= n; i++)
        if (!col[i]) dfs2(i, ++c_cnt);

    for (int i = 1; i <= m; i++) {
        if (col[u_e[i]] == col[v_e[i]] || t_e[i] == 1)
            puts("YES");
        else
            puts(dfn[u_e[i]] > dfn[v_e[i]] ? "YES" : "NO");
    }

    return 0;
}