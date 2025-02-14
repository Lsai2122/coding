#include<stdio.h>
void selection_sort(int a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int m=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[m]>a[j])
            {
                m=j;
            }
        }
        if(i!=m)
        {
            int temp = a[i];
            a[i]=a[m];
            a[m]=temp;    
        }
        
    }
}
int main()
{
    int a[]= {123,41,124,51,2,4,14,5,35,1,2};
    selection_sort(a,sizeof(a)/sizeof(a[0]));
}