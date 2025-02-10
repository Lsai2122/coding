#include<stdio.h>
void sqaure_sort(int *a,int n)
{
    int i=0;
    while(a[i]<0)
    {
        i++;
    }
    for(int k=0;k<n;k++)
    {
        a[k]=a[k]*a[k];
    }
    while(i>0)
    {
        int j=i-1;
        int temp =a[j];
        while(temp>a[j+1]&&j<n-1)
        {
            a[j]=a[j+1];
            j++;
        }
        a[j]=temp;
        i--;
    }
    return;
}
int main()
{
    int a[]={-7,-3,-1,4,8,12};
    sqaure_sort(a,6);
}