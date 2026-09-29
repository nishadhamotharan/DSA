#include <stdio.h>

#define MAX_VAL 1000005

int div_cnt[MAX_VAL];
long long freq[1005];

void precompute() {
    for (int i = 1; i < MAX_VAL; i++) {
        for (int j = i; j < MAX_VAL; j += i) {
            div_cnt[j]++;
        }
    }
}

int main() {
    precompute();

    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        int d = div_cnt[a];
        freq[d]++;
    }

    long long pairs = 0;
    for (int i = 1; i < 1005; i++) {
        if (freq[i] >= 2) {
            pairs += freq[i] * (freq[i] - 1) / 2;
        }
    }

    printf("%lld\n", pairs);
    return 0;
}