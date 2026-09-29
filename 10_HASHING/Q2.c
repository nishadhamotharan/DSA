#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;

    double phi = (1.0 + sqrt(5.0)) / 2.0;

    while (t--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        if (a > b) {
            long long temp = a;
            a = b;
            b = temp;
        }

        long long k = b - a;
        long long cold_a = (long long)(k * phi);

        if (cold_a == a) {
            printf("Sami\n");
        } else {
            printf("Canthi\n");
        }
    }

    return 0;
}