#include<stdio.h>
void selection_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        int temp = a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
int main()
{
    int a[]={2,10,7,3,5,102,1};
    int n=7;
    selection_sort(a,n);
}