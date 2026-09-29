#include <stdio.h>
#include <string.h>
#define MAXN 100005
int boy_crush[MAXN];
int girl_crush[MAXN];
int target_boy[MAXN];
int target_girl[MAXN];
int beatings_boy[MAXN];
int beatings_girl[MAXN];
void solve() {
    int n;
    if (scanf("%d", &n) != 1) return;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &boy_crush[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &girl_crush[i]);
    }
    for (int i = 1; i <= n; i++) {
        beatings_boy[i] = 0;
        beatings_girl[i] = 0;
        target_boy[i] = 0;
        target_girl[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int g = boy_crush[i];
        int b = girl_crush[g];
        if (b != i) {
            target_boy[i] = b;
            beatings_boy[b]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int b = girl_crush[i];
        int g = boy_crush[b];
        if (g != i) {
            target_girl[i] = g;
            beatings_girl[g]++;
        }
    }
    int max_beatings = 0;
    for (int i = 1; i <= n; i++) {
        if (beatings_boy[i] > max_beatings) max_beatings = beatings_boy[i];
        if (beatings_girl[i] > max_beatings) max_beatings = beatings_girl[i];
    }
    int mutual_pairs = 0;
    for (int i = 1; i <= n; i++) {
        int j = target_boy[i];
        if (j > i && target_boy[j] == i) {
            mutual_pairs++;
        }
    }
    for (int i = 1; i <= n; i++) {
        int j = target_girl[i];
        if (j > i && target_girl[j] == i) {
            mutual_pairs++;
        }
    }
    printf("%d %d\n", max_beatings, mutual_pairs);
}
int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        solve();
    }
    return 0;
}