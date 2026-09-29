#include <stdio.h>

#define MAXN 100005

int S[MAXN];

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    int i;
    for(i=0;i<N;i++) {
        scanf("%d", &S[i]);
    }

    int size = N;
    int Q;
    if (scanf("%d", &Q) != 1) return 0;

    while (Q--) {
        int val;
        scanf("%d", &val);

        int found = 0;
        for (int j = 0; j < size; j++) {
            if (S[j] == val) {
                found = 1;
                break;
            }
        }

        if (!found) {
            S[size++] = val;
        }

        printf("%d\n", size);
    }

    for (int j = 0; j < size; j++) {
        printf("%d", S[j]);
        if (j < size - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}