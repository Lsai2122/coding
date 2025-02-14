#include <stdio.h>

void wave(int a[], int n)
{
    int li=1;int ei=n-1;
    for(int i=0;i<n/2;i++)
    {
        int min=0;int max=0;
        for(int j=li+1;j<n;j++)
        {
            if(a[i]<a[min]){min=i;}
            if(a[i]>a[max]){max=i;}
        }
        int temp = a[li];
        a[li]=a[min];
        a[min]=temp;
        li+=2;
        temp = a[ei];
        a[ei]=a[max];
        ei-=2;
    }
}
int main()
{
    int a[] = {3, 6, 5, 10, 7, 20};
    int n = 6;
    wave(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}