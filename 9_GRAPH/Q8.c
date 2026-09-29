#include <stdio.h>

#define MAXN 200005

int head[MAXN], to[MAXN * 2], nxt[MAXN * 2], e_cnt;
int matched[MAXN];
int ans = 0;

void link(int u, int v) {
    e_cnt++;
    to[e_cnt] = v;
    nxt[e_cnt] = head[u];
    head[u] = e_cnt;
}

void dfs(int p,int i) {
    for (int e = head[i]; e; e = nxt[e]) {
        int c = to[e];
        if (c != p) {
            dfs(i, c);
            if (!matched[i] && !matched[c]) {
                matched[i] = 1;
                matched[c] = 1;
                ans++;
            }
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int k = 1; k < n; k++) {
        int u, v;
        scanf("%d %d", &u, &v);
        link(u, v);
        link(v, u);
    }

    dfs(0, 1);

    printf("%d\n", ans);
    return 0;
}