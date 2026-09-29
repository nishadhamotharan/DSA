#include <stdio.h>

int main() {
    int n, i, j;
    if (scanf("%d", &n) != 1) return 0;

    int arr[1005];
    int max = 0;

    for(i=0;i<n;i++) {
        scanf("%d", &arr[i]);
        if(arr[i]>max) {
            max = arr[i];
        }
    }

    int freq[10005] = {0};
    for(i=0;i<n;i++) {
        freq[arr[i]]++;
    }

    long long ans = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (freq[arr[i]] == freq[arr[j]]) {
                ans++;
            }
        }
    }

    printf("%lld\n", ans);
    return 0;
}