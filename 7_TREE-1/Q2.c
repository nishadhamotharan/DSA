#include <stdio.h>

#define MAXN 100005

int pre[MAXN];
int in[MAXN];
int in_pos[MAXN];
int post[MAXN];
int post_idx = 0;

void buildPostorder(int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end || in_start > in_end) {
        return;
    }

    int root_val = pre[pre_start];
    int root_in_idx = in_pos[root_val];
    int left_size = root_in_idx - in_start;

    buildPostorder(pre_start + 1, pre_start + left_size, in_start, root_in_idx - 1);
    buildPostorder(pre_start + left_size + 1, pre_end, root_in_idx + 1, in_end);

    post[post_idx++] = root_val;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &in[i]);
        in_pos[in[i]] = i;
    }

    buildPostorder(0, n - 1, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d", post[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}