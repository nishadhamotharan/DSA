#include <stdio.h>

int search(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    while (scanf("%d %d", &a, &b) == 2) {
        printf("%d\n", search(a, b));
    }
    return 0;
}