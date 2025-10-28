#include <stdio.h>
#include <stdlib.h>


int comparison2 = 0;  
int comparison3 = 0;

int binarysearch(int arr[], int low, int high, int key);
int ternarysearch(int arr[], int low, int high, int key);

int binarysearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        comparison2++;
        if (arr[mid] == key) return mid;

        comparison2++;
        if (key < arr[mid]) return binarysearch(arr, low, mid - 1, key);
        else return binarysearch(arr, mid + 1, high, key);
    }
    return -1;
}

int ternarysearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        comparison3++;
        if (arr[mid1] == key) return mid1;

        comparison3++;
        if (arr[mid2] == key) return mid2;

        comparison3++;
        if (arr[mid1] > key) return ternarysearch(arr, low, mid1 - 1, key);

        comparison3++;
        if (arr[mid2] < key) return ternarysearch(arr, mid2 + 1, high, key);

        return ternarysearch(arr, mid1 + 1, mid2 - 1, key);
    }
    return -1;
}




int main() {
    int t;
    int n;
    scanf("%d",&t);

    
    FILE *fp = fopen("output.dat", "a"); // append results for multiple runs
    if (!fp) {
        printf("Error opening file\n");
        return 1;
    }

    while(t--)
    {
    printf("Enter the size of array\n");
    scanf("%d", &n);
    printf("%d\n",n);

    int arr[n];
    printf("Enter the array elements\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n",arr);

    int key;
    printf("Enter the value of key\n");
    scanf("%d", &key);
    printf("%d\n",key);
    
    comparison2=0;
    comparison3=0;      
    int index2 = binarysearch(arr, 0, n - 1, key);
    int index3 = ternarysearch(arr, 0, n - 1, key);
    printf("%d\n",index2);
    printf("%d %d %d\n", n, comparison2, comparison3);
    fprintf(fp, "%d %d %d\n", n, comparison2, comparison3);
    
}
printf("Results appended to output.dat\n");
fclose(fp);
return 0;
}
