#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int d;
    long long h;
} Flat;

int compare(const void *a, const void *b)
{
    Flat *p = (Flat *)a;
    Flat *q = (Flat *)b;

    if (p->d < q->d)
        return -1;
    if (p->d > q->d)
        return 1;
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        Flat *a = (Flat *)malloc(n * sizeof(Flat));

        long long total = 0;

        for (int i = 0; i < n; i++)
        {
            int x, y;
            long long h;

            scanf("%d %d %lld", &x, &y, &h);

            a[i].d = y - x;
            a[i].h = h;

            total += h;
        }

        qsort(a, n, sizeof(Flat), compare);

        long long left = 0;
        int possible = 0;

        int i = 0;

        while (i < n)
        {
            int j = i;
            long long group = 0;
            while (j < n && a[j].d == a[i].d)
            {
                group += a[j].h;
                j++;
            }
            long long right = total - left - group;

            if (left == right)
            {
                possible = 1;
                break;
            }

            left += group;
            i = j;
        }

        if (possible)
            printf("YES\n");
        else
            printf("NO\n");

        free(a);
    }
    return 0;
}