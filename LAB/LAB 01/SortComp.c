#include <stdio.h>

// Global counters for element comparisons
int binary_comparisons = 0, ternary_comparisons = 0;

// Binary Search (Iterative)
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int mid = l + (r - l) / 2;

        binary_comparisons++;  // Compare arr[mid] == x?
        if (arr[mid] == x) return mid;

        binary_comparisons++;  // Compare arr[mid] < x?
        if (arr[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

// Ternary Search (Recursive)
int ternarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        ternary_comparisons++;  // Compare arr[mid1] == x?
        if (arr[mid1] == x) return mid1;

        ternary_comparisons++;  // Compare arr[mid2] == x?
        if (arr[mid2] == x) return mid2;

        ternary_comparisons++;  // Compare x < arr[mid1]?
        if (x < arr[mid1])
            return ternarySearch(arr, l, mid1 - 1, x);

        ternary_comparisons++;  // Compare x > arr[mid2]?
        if (x > arr[mid2])
            return ternarySearch(arr, mid2 + 1, r, x);

        // Search in the middle segment
        return ternarySearch(arr, mid1 + 1, mid2 - 1, x);
    }
    return -1;
}

// Bubble Sort to sort the input array
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

int main() {
    int n, x;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Sort the array before searching
    bubbleSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("Enter element to search: ");
    scanf("%d", &x);

    // Run Binary Search and count comparisons
    binary_comparisons = 0;
    int res_b = binarySearch(arr, 0, n - 1, x);

    // Run Ternary Search and count comparisons
    ternary_comparisons = 0;
    int res_t = ternarySearch(arr, 0, n - 1, x);

    // Print results
    if (res_b != -1)
        printf("\nBinary Search:  Element found at index %d\n", res_b);
    else
        printf("\nBinary Search:  Element not found\n");

    printf("Comparisons in Binary Search: %d\n", binary_comparisons);

    if (res_t != -1)
        printf("\nTernary Search: Element found at index %d\n", res_t);
    else
        printf("\nTernary Search: Element not found\n");

    printf("Comparisons in Ternary Search: %d\n", ternary_comparisons);

    return 0;
}
