#include <stdio.h>

// Utility function to swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find median of first, middle, and last element
int medianOfThree(int arr[], int low, int high) {
    int mid = (low + high) / 2;

    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);
    if (arr[low] > arr[high])
        swap(&arr[low], &arr[high]);
    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);

    // Place median at high-1
    swap(&arr[mid], &arr[high - 1]);
    return arr[high - 1];
}

// Partition using median as pivot
int partition(int arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = low, j = high - 1;

    while (1) {
        while (arr[++i] < pivot) {}
        while (arr[--j] > pivot) {}

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }

    swap(&arr[i], &arr[high - 1]); // Restore pivot
    return i;
}

// Quick Sort using Median-of-Three pivot
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        if (high - low + 1 <= 3) {
            // For small segments, use simple sort
            if (arr[low] > arr[high])
                swap(&arr[low], &arr[high]);
        } else {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
}

// Utility function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("Sorted Array (Quick Sort with Median Pivot):\n");
    printArray(arr, n);

    return 0;
}
