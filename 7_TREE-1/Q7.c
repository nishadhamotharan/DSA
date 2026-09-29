#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005
#define MOD1 1000000007ULL
#define BASE1 10007ULL

typedef struct {
    int to;
    int next;
} Edge;

Edge edges[2 * MAXN];
int head[MAXN], edge_cnt;
int degree[MAXN];
int parent_node[MAXN];

void add_edge(int u, int v) {
    edges[edge_cnt].to = v;
    edges[edge_cnt].next = head[u];
    head[u] = edge_cnt++;
}

void dfs(int u, int p) {
    parent_node[u] = p;
    for (int e = head[u]; e != -1; e = edges[e].next) {
        int v = edges[e].to;
        if (v != p) {
            dfs(v, u);
        }
    }
}

typedef struct HashNode {
    unsigned long long val;
    struct HashNode *next;
} HashNode;

#define HASH_SIZE 1000003
HashNode *hash_table[HASH_SIZE];

int insert_hash(unsigned long long val) {
    unsigned int idx = val % HASH_SIZE;
    HashNode *cur = hash_table[idx];
    while (cur) {
        if (cur->val == val) return 0;
        cur = cur->next;
    }
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->val = val;
    newNode->next = hash_table[idx];
    hash_table[idx] = newNode;
    return 1;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
        degree[i] = 0;
    }
    edge_cnt = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
        degree[u]++;
        degree[v]++;
    }

    dfs(1, 0);

    long long distinct_trips = 0;

    for (int a = 1; a <= n; a++) {
        unsigned long long current_hash = 0;
        int curr = a;
        while (curr != 0) {
            current_hash = current_hash * BASE1 + (unsigned long long)degree[curr];
            if (insert_hash(current_hash)) {
                distinct_trips++;
            }
            curr = parent_node[curr];
        }
    }

    printf("%lld\n", distinct_trips);

    return 0;
}