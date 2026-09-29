#include <stdio.h>
#include <string.h>
#define N 505
#define M 4005
int to[M], cap[M], flow[M], nxt[M], org[M], hd[N], ec;
int p_nd[N], p_eg[N], q[N], pt[N];
void add(int u, int v) {
    to[ec] = v; cap[ec] = 1; flow[ec] = 0; org[ec] = 1; nxt[ec] = hd[u]; hd[u] = ec++;
    to[ec] = u; cap[ec] = 0; flow[ec] = 0; org[ec] = 0; nxt[ec] = hd[v]; hd[v] = ec++;
}
int bfs(int n,int s,int t) {
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
int main() {
    int n, m, u, v, mf = 0;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    memset(hd, -1, sizeof(hd));
    while (m--) { scanf("%d %d", &u, &v); add(u, v); }

    while (bfs(n, 1, n)) {
        mf++;
        for (int c = n; c != 1; c = p_nd[c]) {
            int e = p_eg[c];
            flow[e]++; flow[e ^ 1]--;
        }
    }
    printf("%d\n", mf);
    while (mf--) {
        int c = 1, l = 0;
        pt[l++] = 1;
        while (c != n) {
            for (int e = hd[c]; e != -1; e = nxt[e]) {
                if (org[e] && flow[e] > 0) {
                    flow[e]--; c = to[e]; pt[l++] = c; break;
                }
            }
        }
        printf("%d\n", l);
        for (int i = 0; i < l; i++) printf("%d%c", pt[i], i == l - 1 ? '\n' : ' ');
    }
    return 0;
}