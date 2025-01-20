#include<stdio.h>
void merging(int arr[],int si,int ei,int mid)
{
    int s1 = mid-si+1;
    int s2 = ei-mid;
    int a[s1];
    int b[s2];
    int k = si;
    for(int i=0;i<s1;i++)
    {
        a[i]=arr[k++];   
    }
    for(int i=0;i<s2;i++)
    {
        b[i]=arr[k++];
    }
    int i=0;
    int j=0;
    k=si;
    while(i<s1&&j<s2)
    {
        if(a[i]<b[j])
        {
            arr[k++]=a[i++];
        }
        else
        {
            arr[k++]=b[j++];
        }
    }
    while(i<s1)
    {
        arr[k++]=a[i++];
    }
    while(j<s2)
    {
        arr[k++]=b[j++];
    }
}
void merge_sort(int arr[],int si,int ei)
{
    int mid = (si+ei)/2;
    if(si<ei)
    {
        merge_sort(arr,si,mid);
        merge_sort(arr,mid+1,ei);
    }
    merging(arr,si,ei,mid);
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}