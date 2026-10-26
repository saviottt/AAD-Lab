#include<stdio.h>

int temp[100];

void merge(int arr[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    
    while(j<=high)
    {
        temp[k++]=arr[j++];
    }
    
    for(i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }
}

void mergesort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}


int main()
{
    int n,arr[100],i,j;
    printf("Enter the number of array elements:");
    scanf("%d",&n);
    printf("Enter the array elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    mergesort(arr,0,n-1);
    printf("The sorted array:");
    for(i=0;i<n;i++)
    {
        printf("%d ",temp[i]);
    }
    return 0;
}
