#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int t;
    printf("Enter number of test cases: ");
    scanf("%d", &t);

    FILE *fp = fopen("input.txt", "w");
    if (!fp) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    fprintf(fp, "%d\n", t); 

    for (int tc = 0; tc < t; tc++) {
        int n = (rand() % 20) + 5; 
        int *arr = (int*)malloc(n * sizeof(int));

       
        arr[0] = rand() % 10;
        for (int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + (rand() % 10 + 1); 
        }

        
        int key;
        if (rand() % 2)
            key = arr[rand() % n]; 
        else
            key = arr[n - 1] + (rand() % 10); 

        
        fprintf(fp, "%d\n", n);      
        for (int i = 0; i < n; i++)
            fprintf(fp, "%d ", arr[i]);
        fprintf(fp, "\n");
        fprintf(fp, "%d\n", key);    

        free(arr);
    }

    fclose(fp);
    printf("Random input written to input.txt\n");
    return 0;
}
