#include<stdio.h>
void quick_sort(int arr[],int l,int h)
{
    int pivot = arr[l];int si = l;int ei = h;
    while(si<ei)
    {
        while(arr[si]<=pivot&&si<h)
            si++;
        while(arr[ei]>=pivot&&ei>l)
            ei--;
        if(si<ei)
        {
            int temp = arr[si];
            arr[si] = arr[ei];
            arr[ei]= temp;
        }
        else
        {
            int temp = arr[l];
            arr[l] = arr[ei];
            arr[ei] = temp;
        }
    }
    if(l<h)
    {
        quick_sort(arr,l,ei-1);
        quick_sort(arr,ei+1,h);
    }
    return;
}
int main()
{
    int n;
    printf("Enter the number of elements : ");scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}