#include <stdio.h>
#include <string.h>

int main() {
    char s[1005];
    if (!fgets(s, sizeof(s), stdin)) return 0;

    int freq[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != '\n' && s[i] != '\r') {
            freq[(unsigned char)s[i]]++;
        }
    }

    int max_freq = 0;
    char best_char = 0;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            best_char = (char)i;
        }
    }

    printf("%c %d\n", best_char, max_freq);

    return 0;
}