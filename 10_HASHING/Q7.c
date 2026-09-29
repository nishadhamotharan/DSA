#include <stdio.h>
#include <stdlib.h>

#define MAX_VALS 2000005

long long arr[2005];
long long max_subarray_sums[MAX_VALS];
int count = 0;

int cmp(const void *a, const void *b) {
    long long x = *(const long long *)a;
    long long y = *(const long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    for (int i = 0; i < n; i++) {
        long long current_sum = 0;
        long long max_sum = -1e18;
        for (int j = i; j < n; j++) {
            current_sum += arr[j];
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
            if (current_sum < 0) {
                current_sum = 0;
            }
            max_subarray_sums[count++] = max_sum;
        }
    }

    qsort(max_subarray_sums, count, sizeof(long long), cmp);

    long long total_unique_sum = 0;
    for (int i = 0; i < count; i++) {
        if (i == 0 || max_subarray_sums[i] != max_subarray_sums[i - 1]) {
            total_unique_sum += max_subarray_sums[i];
        }
    }
    printf("%lld\n", total_unique_sum);
    return 0;
}