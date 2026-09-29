#include <stdio.h>
#include <string.h>
#define N 505
#define M 4005
int to[M], cap[M], flow[M], nxt[M], hd[N], ec;
int p_nd[N], p_eg[N], q[N], u_e[M], v_e[M], vis[N];
void link(int i, int h) {
    to[ec] = h; cap[ec] = 1; flow[ec] = 0; nxt[ec] = hd[i]; hd[i] = ec++;
    to[ec] = i; cap[ec] = 1; flow[ec] = 0; nxt[ec] = hd[h]; hd[h] = ec++;
}
int bfs(int n, int s, int t) {
    memset(p_nd, -1, sizeof(p_nd));
    int h = 0, tl = 0;
    q[tl++] = s; p_nd[s] = s;
    while (h < tl) {
        int u = q[h++];
        for (int e = hd[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (p_nd[v] == -1 && cap[e] > flow[e]) {
                p_nd[v] = u; p_eg[v] = e;
                if (v == t) return 1;
                q[tl++] = v;
            }
        }
    }
    return 0;
}

void dfs(int u) {
    vis[u] = 1;
    for (int e = hd[u]; e != -1; e = nxt[e])
        if (!vis[to[e]] && cap[e] > flow[e]) dfs(to[e]);
}

int main() {
    int n, m, k = 0;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    memset(hd, -1, sizeof(hd));

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u_e[i], &v_e[i]);
        link(u_e[i], v_e[i]);
    }

    while (bfs(n, 1, n)) {
        for (int c = n; c != 1; c = p_nd[c]) {
            int e = p_eg[c];
            flow[e]++; flow[e ^ 1]--;
        }
    }

    dfs(1);
    for (int i = 0; i < m; i++)
        if (vis[u_e[i]] != vis[v_e[i]]) k++;

    printf("%d\n", k);
    for (int i = 0; i < m; i++)
        if (vis[u_e[i]] != vis[v_e[i]]) printf("%d %d\n", u_e[i], v_e[i]);

    return 0;
}