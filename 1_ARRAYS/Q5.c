#include <stdio.h>
int main() {
    char nums[13][256] = {
        "ZERO",
        "ONE",
        "TWO",
        "THREE",
        "FOUR",
        "FIVE",
        "SIX",
        "SEVEN",
        "EIGHT",
        "NINE",
        "TEN",
        "ELEVEN",
        "TWELVE"
    };
    int arr[100];
    int n = 0;
    while (scanf("%d", &arr[n]) == 1 && arr[n] != 999) {
        n++;
    }
    int maxCount[26] = {0};
    for (int i = 0; i < n; i++) {

        int count[26] = {0};

        for (int j = 0; nums[arr[i]][j] != '\0'; j++) {
            count[nums[arr[i]][j] - 'A']++;
        }

        for (int j = 0; j < 26; j++) {
            if (count[j] > maxCount[j]) {
                maxCount[j] = count[j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("0999. ");
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < maxCount[i]; j++) {
            printf("%c ", 'A' + i);
        }
    }

    printf("\n");

    return 0;
}