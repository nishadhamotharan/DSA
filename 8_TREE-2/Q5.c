#include <stdio.h>


int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int a[200005], deg[200005] = {0};
    for (int i = 0; i < n - 2; i++) {
        scanf("%d", &a[i]);
        deg[a[i]]++;
    }

    int ptr = 1;
    while (deg[ptr] != 0) ptr++;
    int leaf = ptr;

    for (int i = 0; i < n - 2; i++) {
        int v = a[i];
        printf("%d %d\n", leaf, v);
        deg[v]--;
        if (v < ptr && deg[v] == 0) {
            leaf = v;
        } else {
            ptr++;
            while (deg[ptr] != 0) ptr++;
            leaf = ptr;
        }
    }
    printf("%d %d\n", leaf, n);
    return 0;
}