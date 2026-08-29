#include <stdio.h>
int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    int arr[N + 1];
    int arr2[N + 1];
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
        arr2[i] = digitSum(arr[i]);
    }
    for (int q = 0; q < Q; q++) {
        int x;
        scanf("%d", &x);
        int answer = -1;
        for (int j = x + 1; j <= N; j++) {
            if (arr[x] < arr[j] && arr2[x] > arr2[j]) {
                answer = j;
                break;
            }
        }
        printf("%d ", answer);
    }
    return 0;
}