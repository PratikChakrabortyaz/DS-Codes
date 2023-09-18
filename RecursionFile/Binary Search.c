/*Array is assumed to be sorted*/

#include<stdio.h>

int binarySearch(int low,int high,int arr[],int item)
{
    int mid;
    if(low>=high)
    {
        return -1;
    }
    mid=(low+high)/2;
    if(item==arr[mid])
    {
        return mid;
    }
    else if(item>arr[mid])
    {
        low=mid+1;
        binarySearch(low,high,arr,item);
    }
    else
    {
        high=mid-1;
        binarySearch(low,high,arr,item);
    }

}

void main()
{
    int n;int item;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements of array:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element to be found:");
    scanf("%d",&item);
    int found=binarySearch(0,n-1,arr,item);
    if(found==-1)
    {
        printf("Element not found");
    }
    else{
        printf("Element is found in index %d",found);
    }




}
