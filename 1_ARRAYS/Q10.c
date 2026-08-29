#include <stdio.h>
#define MAXN 100
int s[MAXN];
void sol(int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] > s[j]) {
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    int treats = 1;
    int total = 0;
    total = treats;
    for (int i = 1; i < n; i++) {
        if (s[i] > s[i - 1]) {
            treats++;
        }
        total = total + treats;
    }
    printf("%d\n", total);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        sol(n);
    }
    return 0;
}