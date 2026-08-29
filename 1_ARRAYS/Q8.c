#include <stdio.h>
int main() {
    int N;
    scanf("%d", &N);
    while (N--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int C[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &C[i][j]);
            }
        }
        int X1, Y1, X2, Y2;
        scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
        int sum = 0;
        for (int i = X1 - 1; i <= X2 - 1; i++) {
            for (int j = Y1 - 1; j <= Y2 - 1; j++) {
                sum = sum + C[i][j];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}