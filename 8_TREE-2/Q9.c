#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005
typedef struct {
    int to;
    int next;
} Edge;
Edge edges[2 * MAXN];
int head[MAXN], edge_cnt;
char s[MAXN];
int count_char[MAXN][26];
void add_edge(int u, int v) {
    edges[edge_cnt].to = v;
    edges[edge_cnt].next = head[u];
    head[u] = edge_cnt++;
}
void dfs(int u, int p) {
    count_char[u][s[u - 1] - 'a'] = 1;

    for (int e = head[u]; e != -1; e = edges[e].next) {
        int v = edges[e].to;
        if (v != p) {
            dfs(v, u);
            for (int c = 0; c < 26; c++) {
                count_char[u][c] += count_char[v][c];
            }   }   }   }
int main() {
    int N, Q;
    if (scanf("%d %d", &N, &Q) != 2) return 0;
    scanf("%s", s);
    for (int i = 1; i <= N; i++) {
        head[i] = -1;
    }
    edge_cnt = 0;
    int i;
    for(i = 0;i<N-1;i ++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    while(Q--) {
        int u;
        char c;
        scanf("%d %c", &u, &c);
        printf("%d\n", count_char[u][c - 'a']);
    }
    return 0;
}