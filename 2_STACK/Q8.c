#include <stdio.h>
long long arr[1000000];
long long st[1000000];
int nge[1000000];
int stack[1000000];
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        nge[i] = -1;
    }
    int top = -1;
    for (int i = 0; i < n; i++) {
        while (top >= 0 && arr[stack[top]] < arr[i]) {
            int j = i;
            if (arr[stack[top]] < arr[j]) {
                nge[stack[top]] = j;
                top--;
            }
        }
        stack[++top] = i;
    }
    long long max_stamina = 0;
    for (int i = n - 1; i >= 0; i--) {
        int j = nge[i];
        if (j == -1) {
            st[i] = arr[i];
        } else {
            st[i] = arr[i] ^ st[j];
        }
        if (st[i] > max_stamina){
            max_stamina = st[i];
        }
    }
    printf("%lld\n", max_stamina);
    return 0;
}
