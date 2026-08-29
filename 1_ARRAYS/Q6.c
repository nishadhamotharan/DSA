#include <stdio.h>
#include <string.h>
#define MAX 6
#define LEN 100
int main() {
    int dollar, items;
    scanf("%d %d", &dollar, &items);
    char name[MAX][LEN];
    int price[MAX];
    int afford[MAX] = {0};
    for (int i = 0; i < items; i++) {
        scanf("%s %d", name[i], &price[i]);
    }
    int remaining = dollar;
    while (1) {
        int minIndex = -1;
        for (int i = 0; i < items; i++) {
            if (afford[i] == 0 && price[i] <= remaining) {
                if (minIndex == -1 || price[i] < price[minIndex]) {
                    minIndex = i;
                }
            }
        }
        if (minIndex == -1) {
            break;
        }

        afford[minIndex] = 1;
        remaining -= price[minIndex];
    }
    int bought = 0;
    for (int i = 0; i < items; i++) {
        if (afford[i] == 1) {
            printf("I can afford %s\n", name[i]);
            bought++;
        } else {
            printf("I can't afford %s\n", name[i]);
        }
    }
    if (bought == 0) {
        printf("I need more Dollar!\n");
    } else {
        printf("%d\n", remaining);
    }

    return 0;
}