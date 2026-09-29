#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    while (t--) {
        int n;
        scanf("%d", &n);

        int a1, b1, a2, b2, c1, d1, c2, d2;
        scanf("%d %d", &a1, &b1);
        scanf("%d %d", &a2, &b2);
        scanf("%d %d", &c1, &d1);
        scanf("%d %d", &c2, &d2);
        int match1 = (a1 == c1 && b1 == d1 && a2 == c2 && b2 == d2);
        int match2 = (a1 == c2 && b1 == d2 && a2 == c1 && b2 == d1);

        if (match1 || match2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}