#include <stdio.h>

#define MAX 100   // maximum size of heap

int heap[MAX];
int heapSize = 0;

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Down (to maintain min heap property)
void heapifydown(int index, int n) {
    int left = 2 * index;
    int right = 2 * index + 1;
    int smallest = index;

    if (left <= n && heap[left] < heap[smallest])
        smallest = left;

    if (right <= n && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifydown(smallest, n);
    }
}

// Print heap
void printheap(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Enter the no. of elements to be inserted in heap\n");
    scanf("%d", &n);
    printf("Enter Heap elements:\n");
    for (int i = 1; i <= n; i++) {   // start from index 1
        scanf("%d", &heap[i]);
    }

    printf("Inserted Heap (Array):\n");
    printheap(n);

    // Build heap by calling heapifydown from n/2 to 1
    for (int j = n / 2; j >= 1; j--) {
        heapifydown(j, n);
    }

    printf("Heapified Heap (Min-Heap):\n");
    printheap(n);

    return 0;
}

