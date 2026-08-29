#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int i = 0;
    int j = n - 1;

    while (i <= j) {

        if (a[i] > a[j]) {
            printf("1 ");
            j--;
        }
        else if (a[i] < a[j]) {
            printf("2 ");
            i++;
        }
        else {
            printf("0 ");
            i++;
            j--;
        }
    }

    return 0;
}