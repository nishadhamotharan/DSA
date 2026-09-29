#include <stdio.h>

#define MAXN 100005

int parent[MAXN];
int sz[MAXN];
int components;
int max_size = 1;

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

int join(int i,int j) {
    int root_i = find(i);
    int root_j = find(j);

    if (root_i != root_j) {
        if (sz[root_i] < sz[root_j]) {
            int temp = root_i;
            root_i = root_j;
            root_j = temp;
        }
        parent[root_j] = root_i;
        sz[root_i] += sz[root_j];

        if (sz[root_i] > max_size) {
            max_size = sz[root_i];
        }
        components--;
    }
    return 0;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    components = n;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (int k = 0; k < m; k++) {
        int u, v;
        scanf("%d %d", &u, &v);
        join(u, v);
        printf("%d %d\n", components, max_size);
    }

    return 0;
}