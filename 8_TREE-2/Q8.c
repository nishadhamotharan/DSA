#include <stdio.h>

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int p[100005];
    int deg[100005] = {0};

    int i;
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &p[i]);
        deg[p[i]]++;
    }

    int cur_k = 1;
    int nodes_in_layer = 1;

    for (int node = 1; node <= n; node++) {
        if (nodes_in_layer == 0) {
            cur_k++;
            nodes_in_layer = cur_k <= k ? cur_k : k;
        }

        printf("%d %d\n", node, cur_k);
        nodes_in_layer--;
    }

    return 0;
}