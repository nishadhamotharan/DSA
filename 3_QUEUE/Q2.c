#include <stdio.h>
#include <string.h>

#define MAX 200005

typedef struct
{
    int len;
    int pref;
    int suff;
    int best;
    char left;
    char right;
} Node;

Node tree[4 * MAX];
char s[MAX];

void pull(int k, int l, int r)
{
    int a = 2 * k;
    int b = 2 * k + 1;

    tree[k].len = tree[a].len + tree[b].len;
    tree[k].left = tree[a].left;
    tree[k].right = tree[b].right;

    tree[k].pref = tree[a].pref;
    tree[k].suff = tree[b].suff;

    if (tree[a].right == tree[b].left)
    {
        if (tree[a].pref == tree[a].len)
            tree[k].pref = tree[a].len + tree[b].pref;

        if (tree[b].suff == tree[b].len)
            tree[k].suff = tree[b].len + tree[a].suff;
    }

    tree[k].best = tree[a].best > tree[b].best
                   ? tree[a].best
                   : tree[b].best;

    if (tree[a].right == tree[b].left)
    {
        int x = tree[a].suff + tree[b].pref;

        if (x > tree[k].best)
            tree[k].best = x;
    }
}

void build(int k, int l, int r)
{
    if (l == r)
    {
        tree[k].len = 1;
        tree[k].pref = 1;
        tree[k].suff = 1;
        tree[k].best = 1;
        tree[k].left = s[l];
        tree[k].right = s[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);

    pull(k, l, r);
}

void update(int k, int l, int r, int pos)
{
    if (l == r)
    {
        tree[k].left = s[pos];
        tree[k].right = s[pos];
        return;
    }

    int mid = (l + r) / 2;

    if (pos <= mid)
        update(2 * k, l, mid, pos);
    else
        update(2 * k + 1, mid + 1, r, pos);

    pull(k, l, r);
}

int main()
{
    int n, m;

    scanf("%s", s + 1);
    n = strlen(s + 1);

    scanf("%d", &m);

    build(1, 1, n);

    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);

        if (s[x] == '0')
            s[x] = '1';
        else
            s[x] = '0';

        update(1, 1, n, x);

        printf("%d", tree[1].best);

        if (i < m - 1)
            printf(" ");
    }

    return 0;
}