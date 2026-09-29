#include <stdio.h>
#include <string.h>
typedef struct {
    char s[15];
    long long a, b, c;
} Fest;

Fest f[1005];

void upd(Fest *x, long long v) {
    if (v > x->a) { x->c = x->b; x->b = x->a; x->a = v; }
    else if (v > x->b) { x->c = x->b; x->b = v; }
    else if (v > x->c) { x->c = v; }
}

int main() {
    int t, n;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        scanf("%d", &n);
        int cnt = 0;
        while (n--) {
            char name[15];
            long long v;
            scanf("%s %lld", name, &v);
            int idx = -1;
            for (int i = 0; i < cnt; i++) {
                if (strcmp(f[i].s, name) == 0) { idx = i; break; }
            }
            if (idx == -1) {
                idx = cnt++;
                strcpy(f[idx].s, name);
                f[idx].a = f[idx].b = f[idx].c = 0;
            }
            upd(&f[idx], v);
        }

        int best = 0;
        long long max_sum = f[0].a + f[0].b + f[0].c;
        for (int i = 1; i < cnt; i++) {
            long long cur = f[i].a + f[i].b + f[i].c;
            if (cur > max_sum || (cur == max_sum && strcmp(f[i].s, f[best].s) < 0)) {
                max_sum = cur;
                best = i;
            }
        }
        printf("%s %lld\n", f[best].s, max_sum);
    }
    return 0;
}