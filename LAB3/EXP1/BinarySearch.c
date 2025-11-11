#include <stdio.h>

// Recursive Binary Search Function
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;  // Key found

        if (key < arr[mid])
            return binarySearchRecursive(arr, low, mid - 1, key);
        else
            return binarySearchRecursive(arr, mid + 1, high, key);
    }
    return -1; // Key not found
}

// Iterative (Non-Recursive) Binary Search Function
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;  // Key found

        if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1; // Key not found
}

int main() {
    int n, key, choice, pos;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    printf("\nChoose search method:\n");
    printf("1. Recursive Binary Search\n");
    printf("2. Iterative Binary Search\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        pos = binarySearchRecursive(arr, 0, n - 1, key);
    } else {
        pos = binarySearchIterative(arr, n, key);
    }

    if (pos != -1)
        printf("Key %d found at index %d (0-based index)\n", key, pos);
    else
        printf("Key %d not found in the list.\n", key);

    return 0;
}
