#include <stdio.h>

#define MAXN 1005

int pref[MAXN][MAXN];
char grid[MAXN][MAXN];

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        scanf("%s", grid[i] + 1);
        for (int j = 1; j <= n; j++) {
            int is_tree = (grid[i][j] == '*');
            pref[i][j] = is_tree + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }

    while (q--) {
        int y1, x1, y2, x2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

        int ans = pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] + pref[y1 - 1][x1 - 1];
        printf("%d\n", ans);
    }

    return 0;
}