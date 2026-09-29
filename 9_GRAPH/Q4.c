#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int parent[MAXN];

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void union_set(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i != root_j) {
        parent[root_i] = root_j;
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while(m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        union_set(u, v);
    }

    int reps[MAXN];
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            reps[count++] = i;
        }
    }

    printf("%d\n", count - 1);
    for (int i = 1; i < count; i++) {
        printf("%d %d\n", reps[i - 1], reps[i]);
    }

    return 0;
}