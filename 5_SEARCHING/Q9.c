#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N;
        long long D;

        scanf("%d %lld", &N, &D);

        long long X[N];

        for (int i = 0; i < N; i++) {
            scanf("%lld", &X[i]);
        }

        long long day = D;

        for (int i = N - 1; i >= 0; i--) {
            day = (day / X[i]) * X[i];
        }

        printf("%lld\n", day);
    }

    return 0;
}