#include <stdio.h>
#include <stdlib.h>

#define MAX_VAL 2000005

int freq[MAX_VAL];

int main() {
    int m, q, n;
    if (scanf("%d %d %d", &m, &q, &n) != 3) return 0;

    int max_a = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        for (int k = -q; k <= q; k++) {
            int val = a + k * m;
            if (val >= 0 && val < MAX_VAL) {
                freq[val]++;
                if (val > max_a) {
                    max_a = val;
                }
            }
        }
    }

    int highest_rating = 0;
    for (int i = 0; i <= max_a; i++) {
        if (freq[i] > highest_rating) {
            highest_rating = freq[i];
        }
    }

    printf("%d\n", highest_rating);
    return 0;
}