#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comparison2=0;
int comparison3=0;

int binarysearch(int arr[],int low,int high, int key);
int ternarysearch(int arr[], int low, int high, int key);


int binarysearch(int arr[],int low,int high, int key)
{
    int mid;
    if(low<=high)
{
    mid = low + (high-low)/2;
    comparison2++;
    if(arr[mid]==key)
    {    
    return mid;
    }
    comparison2++;
    if (key<arr[mid])
    {
    return binarysearch(arr,low,mid-1,key);
    }
    else
    {
    return binarysearch(arr,mid+1,high,key);
    }
}

return -1;
}

int ternarysearch(int arr[], int low, int high, int key)
{
    if(low<=high)
    {
        int mid1=low + (high-low)/3;
        int mid2=high - (high-low)/3;
        
        comparison3++;
        if(arr[mid1]==key)
        {
            return mid1;
        }
        
        comparison3++;
        if(arr[mid2]==key)
        {
            return mid2;
        }

        comparison3++;
        if(arr[mid1]>key)
        {
            return ternarysearch(arr,low,mid1-1,key);

        }

        comparison3++;
        if(arr[mid2]<key)
        {
            return ternarysearch(arr,mid2+1,high,key);

        }
        else
        {
            return ternarysearch(arr,mid1+1,mid2-1,key);

        }
    }

    
    return -1;
}

int main()
{
    int n;
    
    printf("Enter the size of array\n");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the array elements\n");

    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int key;
    printf("Enter the value of key\n");
    scanf("%d",&key);

    int index2 = binarysearch(arr,0,n-1,key);
    int index3 = ternarysearch(arr,0,n-1,key);

    if (index2 != -1)
    {
    printf("Index of Key is %d\n",index2);
    printf("Index of Key is %d\n",index3);
    printf("No. of Comparison(Binary Search) made is %d\n", comparison2);
    printf("No. of Comparison(Ternary Search) made is %d\n", comparison3);
     
    }
    
    else
    {
    printf("Key not found by Binary Search\n");
    printf("Key not found by Ternary Search\n");
    printf("No. of Comparison(Binary Search) made is %d\n", comparison2);
    printf("No. of Comparison(Ternary Search) made is %d\n", comparison3);
    }
    


}



