#include<stdio.h>
void insertion_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int j=i;
        int temp = a[j+1];
        while(j>=0&&a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    int a[]= {123,41,124,51,2,4,14,5,35,1,2};
    insertion_sort(a,sizeof(a)/sizeof(a[0]));
}