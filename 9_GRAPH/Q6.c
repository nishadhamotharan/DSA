#include <stdio.h>
#include <string.h>
#define N 1005
#define M 3005
int head[N], to[M * 2], cap[M * 2], flow[M * 2], nxt[M * 2], e_cnt;
int p_node[N], p_edge[N], q[N];

void link(int u,int v) {
    to[e_cnt] = v; cap[e_cnt] = 1; flow[e_cnt] = 0; nxt[e_cnt] = head[u]; head[u] = e_cnt++;
    to[e_cnt] = u; cap[e_cnt] = 0; flow[e_cnt] = 0; nxt[e_cnt] = head[v]; head[v] = e_cnt++;
}
int bfs(int n, int s, int t) {
    memset(p_node, -1, sizeof(p_node));
    int h = 0, tl = 0;
    q[tl++] = s; p_node[s] = s;
    while (h < tl) {
        int u = q[h++];
        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            if (p_node[v] == -1 && cap[e] > flow[e]) {
                p_node[v] = u; p_edge[v] = e;
                if (v == t) return 1;
                q[tl++] = v;
            }
        }
    }
    return 0;
}
int main() {
    int n, m, k, u, v, ans = 0;
    if (scanf("%d %d %d", &n, &m, &k) != 3) return 0;

    memset(head, -1, sizeof(head));
    int s = 0, t = n + m + 1;

    for (int i = 1; i <= n; i++) link(s, i);
    for (int i = 1; i <= m; i++) link(n + i, t);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &u, &v);
        link(u, n + v);
    }

    while (bfs(t, s, t)) {
        ans++;
        for (int cur = t; cur != s; cur = p_node[cur]) {
            int e = p_edge[cur];
            flow[e] += 1;
            flow[e ^ 1] -= 1;
        }
    }

    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        for (int e = head[i]; e != -1; e = nxt[e]) {
            if (to[e] > n && to[e] <= n + m && flow[e] == 1) {
                printf("%d %d\n", i, to[e] - n);
            }
        }
    }
    return 0;
}