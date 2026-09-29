#include <stdio.h>

#define N 200005
#define M 400005

int h[N], to[M], nxt[M], ec;
int rh[N], rto[M], rnxt[M], rec;
int ord[N], oc, comp[N], cc, vis[N];
char ans[N];
void link(int i,int j) {
    to[++ec] = j; nxt[ec] = h[i]; h[i] = ec;
    rto[++rec] = i; rnxt[rec] = rh[j]; rh[j] = rec;
}
int get_v(int x, char s) { return s == '+' ? 2 * x - 1 : 2 * x; }
int neg(int u) { return u % 2 ? u + 1 : u - 1; }
void d1(int u) {
    vis[u] = 1;
    for (int e = h[u]; e; e = nxt[e])
        if (!vis[to[e]]) d1(to[e]);
    ord[oc++] = u;
}
void d2(int u, int c) {
    comp[u] = c;
    for (int e = rh[u]; e; e = rnxt[e])
        if (!comp[rto[e]]) d2(rto[e], c);
}
int main() {
    int n, m, u, v;
    char s1[3], s2[3];
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int k = 0; k < n; k++) {
        scanf("%s %d %s %d", s1, &u, s2, &v);
        int l1 = get_v(u, s1[0]), l2 = get_v(v, s2[0]);
        link(neg(l1), l2);
        link(neg(l2), l1);
    }
    for (int i = 1; i <= 2 * m; i++)
        if (!vis[i]) d1(i);
    for (int i = oc - 1; i >= 0; i--)
        if (!comp[ord[i]]) d2(ord[i], ++cc);
    for (int i = 1; i <= m; i++) {
        int p = 2 * i - 1, ng = 2 * i;
        if (comp[p] == comp[ng]) return puts("IMPOSSIBLE"), 0;
        ans[i] = comp[p] > comp[ng] ? '+' : '-';
    }
    for (int i = 1; i <= m; i++)
        printf("%c%c", ans[i], i == m ? '\n' : ' ');
    return 0;
}