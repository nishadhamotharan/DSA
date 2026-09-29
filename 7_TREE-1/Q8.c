#include <stdio.h>
#include <stdlib.h>

#define MAXN 200005

typedef struct {
    char type;
    int k,x,a,b;
} Query;
int n, q;
int salary[MAXN];
Query queries[MAXN];
int all_vals[3 * MAXN];
int bit[3 * MAXN];
int m = 0;
int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
int get_rank(int val) {
    int low = 0, high = m - 1, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (all_vals[mid] <= val) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans + 1;
}
void update(int idx, int delta) {
    for (; idx <= m; idx += idx & -idx) {
        bit[idx] += delta;
    }
}
int query_bit(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

int main() {
    if (scanf("%d %d", &n, &q) != 2) return 0;

    int total_vals = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &salary[i]);
        all_vals[total_vals++] = salary[i];
    }

    for (int i = 0; i < q; i++) {
        char op[4];
        scanf("%s", op);
        queries[i].type = op[0];
        if (op[0] == '!') {
            scanf("%d %d", &queries[i].k, &queries[i].x);
            all_vals[total_vals++] = queries[i].x;
        } else {
            scanf("%d %d", &queries[i].a, &queries[i].b);
            all_vals[total_vals++] = queries[i].a;
            all_vals[total_vals++] = queries[i].b;
        }
    }

    qsort(all_vals, total_vals, sizeof(int), compare);

    m = 0;
    for (int i = 0; i < total_vals; i++) {
        if (i == 0 || all_vals[i] != all_vals[i - 1]) {
            all_vals[m++] = all_vals[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        update(get_rank(salary[i]), 1);
    }

    for (int i = 0; i < q; i++) {
        if (queries[i].type == '!') {
            int emp = queries[i].k;
            int new_val = queries[i].x;
            update(get_rank(salary[emp]), -1);
            salary[emp] = new_val;
            update(get_rank(salary[emp]), 1);
        } else {
            int left_rank = get_rank(queries[i].a - 1);
            int right_rank = get_rank(queries[i].b);
            int count = query_bit(right_rank) - query_bit(left_rank);
            printf("%d\n", count);
        }
    }
    return 0;
}