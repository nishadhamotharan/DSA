#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[],int n,int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int arr[1005];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build max-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    int total_sum = 0;
    while (k--) {
        int max_val = arr[0];
        total_sum += max_val;
        arr[0] = max_val / 2;
        heapify(arr, n, 0);
    }

    printf("%d\n", total_sum);
    return 0;
}