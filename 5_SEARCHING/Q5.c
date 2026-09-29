#include <stdio.h>

void solve() {
    int m;
    if (scanf("%d", &m) != 1) return;
    
    char s[105];
    if (scanf("%s", s) != 1) return;
    
    int k = (m + 1) / 2;
    int current_sum = 0;
    
    for (int i = 0; i < k; i++) {
        current_sum += (s[i] - '0');
    }
    
    int max_sum = current_sum;
    
    for (int i = k; i < m; i++) {
        current_sum += (s[i] - '0') - (s[i - k] - '0');
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }
    
    printf("%d\n", max_sum);
}

int main() {
    int t;
    if (scanf("%d", &t) == 1) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
