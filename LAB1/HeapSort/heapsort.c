#include <stdio.h>

#define MAX 100   // maximum size of heap

int heap[MAX];
int heapSize = 0;

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up (for newly inserted element)
void heapifyUp(int index) {
    int parent = index / 2;
    if (parent >= 1 && heap[parent] > heap[index]) {
        swap(&heap[parent], &heap[index]);
        heapifyUp(parent);
    }
}

// Insert element into heap
void insert(int value) {
    if (heapSize >= MAX - 1) {
        printf("Heap overflow!\n");
        return;
    }
    heapSize++;
    heap[heapSize] = value;   // insert at end
    heapifyUp(heapSize);      // fix heap property
}

// Print heap as array
void printHeap() {
    printf("Heap array: ");
    for (int i = 1; i <= heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int n, val;
    printf("Enter number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &val);
        insert(val);
        printHeap();
    }

    return 0;
}
