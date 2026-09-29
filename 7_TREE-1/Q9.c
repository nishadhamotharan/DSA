#include <stdio.h>

#define MAXN 1005

int parent1[MAXN], parent2[MAXN];

int find1(int i) {
    if (parent1[i] == i)
        return i;
    return parent1[i] = find1(parent1[i]);
}

void union1(int i, int j) {
    int root_i = find1(i);
    int root_j = find1(j);
    if (root_i != root_j) {
        parent1[root_i] = root_j;
    }
}

int find2(int i) {
    if (parent2[i] == i)
        return i;
    return parent2[i] = find2(parent2[i]);
}

void union2(int i, int j) {
    int root_i = find2(i);
    int root_j = find2(j);
    if (root_i != root_j) {
        parent2[root_i] = root_j;
    }
}

struct Edge {
    int u, v;
} added_edges[MAXN];

int main() {
    int n, m1, m2;
    if (scanf("%d %d %d", &n, &m1, &m2) != 3) return 0;

    for (int i = 1; i <= n; i++) {
        parent1[i] = i;
        parent2[i] = i;
    }

    for (int i = 0; i < m1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        union1(u, v);
    }

    for (int i = 0; i < m2; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        union2(u, v);
    }

    int edge_count = 0;

    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (find1(u) != find1(v) && find2(u) != find2(v)) {
                union1(u, v);
                union2(u, v);
                added_edges[edge_count].u = u;
                added_edges[edge_count].v = v;
                edge_count++;
            }
        }
    }

    printf("%d\n", edge_count);
    for (int i = 0; i < edge_count; i++) {
        printf("%d %d\n", added_edges[i].u, added_edges[i].v);
    }

    return 0;
}