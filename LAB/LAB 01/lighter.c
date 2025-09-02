#include <stdio.h>

// Function to find defective coin recursively using ternary approach
int findDefectiveCoin(int arr[], int l, int r, int normalWeight) {
    
    if (l == r) {
        if (arr[l] < normalWeight)
            return l;
        else
            return -1;
    }

    int length = r - l + 1;
    int third = length / 3;

    int mid1 = l + third - 1;
    int mid2 = mid1 + third + 1;

    
    if (mid1 >= r) mid1 = l + (length / 3) - 1;
    if (mid2 > r) mid2 = r;

    
    int sumA = 0, sumB = 0, sumC = 0;

    for (int i = l; i <= mid1; i++) sumA += arr[i];
    for (int i = mid1 + 1; i <= mid2; i++) sumB += arr[i];
    for (int i = mid2 + 1; i <= r; i++) sumC += arr[i];


    if (sumA < sumB) {
        return findDefectiveCoin(arr, l, mid1, normalWeight);
    } else if (sumB < sumA) {
        return findDefectiveCoin(arr, mid1 + 1, mid2, normalWeight);
    } else {
        return findDefectiveCoin(arr, mid2 + 1, r, normalWeight);
    }
}


int getNormalWeight(int arr[], int n) {
    if (n < 2) return arr[0];

    if (arr[0] == arr[1]) return arr[0];


    if (n > 2) {
        if (arr[1] == arr[2]) return arr[1];
        else return arr[0];
    } else {

        return (arr[0] > arr[1]) ? arr[0] : arr[1];
    }
}

int main() {
    int n;
    printf("Enter number of coins: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the weights of coins:\n");
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int normalWeight = getNormalWeight(arr, n);

    int defectiveIndex = findDefectiveCoin(arr, 0, n - 1, normalWeight);

    if (defectiveIndex == -1) {
        printf("No defective (lighter) coin found.\n");
    } else {
        printf("Defective (lighter) coin found at index: %d\n", defectiveIndex);
        printf("Weight: %d (Normal weight: %d)\n", arr[defectiveIndex], normalWeight);
    }

    return 0;
}
