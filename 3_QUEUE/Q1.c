#include <stdio.h>

#define MAX 100000

long long heap[MAX];
int size = 0;

void insert(long long x) {
    int i = size++;
    
    heap[i] = x;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] >= heap[i])
            break;

        long long temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

long long deleteMax() {
    long long max = heap[0];

    heap[0] = heap[--size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        long long temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }

    return max;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        long long x;
        scanf("%lld", &x);

        insert(x);

        if (size < 3) {
            printf("-1\n");
        }
        else {
            long long a = deleteMax();
            long long b = deleteMax();
            long long c = heap[0];

            printf("%lld\n", a * b * c);

            insert(b);
            insert(a);
        }
    }

    return 0;
}