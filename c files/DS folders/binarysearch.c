#include<stdio.h>
int bina_search(int arr[],int n,int key)
{
    int si=0;int ei=n-1;int mid=(si+ei)/2;
    while(si<=ei)
    {
        int mid = (si+ei)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]<key)
        {
            si=mid+1;
        }
        else{
            ei = mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[10]= {1,2,4,5,10,21,31,40,90,1001};
    int n;
    printf("Enter the number to be searched : ");
    scanf("%d",&n);
    int r_val = bina_search(arr,10,n);
    if(r_val == -1)
    {
        printf("NOT Found");
    }
    else
    {
        printf("Element found at index : %d",r_val);
    }
}