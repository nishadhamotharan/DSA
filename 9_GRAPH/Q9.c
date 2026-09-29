#include <stdio.h>
#include <string.h>

#define N 505
#define M 2005

int to[N][M], cap[N][M], flow[N][M], rev[N][M], orig[N][M], deg[N];
int p_nd[N], p_eg[N], q[N], pt[N];

int bfs(int n,int s,int t) {
    memset(p_nd, -1, sizeof(p_nd));
    int h = 0, tl = 0;
    q[tl++] = s; p_nd[s] = s;
    while (h < tl) {
        int u = q[h++];
        for (int i = 0; i < deg[u]; i++) {
            int v = to[u][i];
            if (p_nd[v] == -1 && cap[u][i] > flow[u][i]) {
                p_nd[v] = u; p_eg[v] = i;
                if (v == t) return 1;
                q[tl++] = v;
            }
        }
    }
    return 0;
}
void add_edge(int u, int v) {
    int iu = deg[u]++, iv = deg[v]++;
    to[u][iu] = v; cap[u][iu] = 1; rev[u][iu] = iv; orig[u][iu] = 1;
    to[v][iv] = u; cap[v][iv] = 0; rev[v][iv] = iu; orig[v][iv] = 0;
}
int main() {
    int n, m, u, v, tf = 0;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    while (m--) { scanf("%d %d", &u, &v); add_edge(u, v); }

    while (bfs(n, 1, n)) {
        tf++;
        for (int c = n; c != 1; c = p_nd[c]) {
            int p = p_nd[c], i = p_eg[c];
            flow[p][i]++;
            flow[c][rev[p][i]]--;
        }
    }

    printf("%d\n", tf);
    for (int k = 0; k < tf; k++) {
        int c = 1, l = 0;
        pt[l++] = 1;
        while (c != n) {
            for (int i = deg[c] - 1; i >= 0; i--) {
                if (orig[c][i] && flow[c][i] > 0) {
                    flow[c][i]--; c = to[c][i]; pt[l++] = c; break;
                }
            }
        }
        printf("%d\n", l);
        for (int i = 0; i < l; i++) printf("%d%c", pt[i], i == l - 1 ? '\n' : ' ');
    }
    return 0;
}