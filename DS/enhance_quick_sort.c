#include<stdio.h>
void quick_sort(int *a,int l,int h)
{
    int size = h-l+1;
    if(size>10)
    {
        int pivot = a[l];int si=l;int ei = h;
        while(si<ei)
        {
            while(a[si]<=pivot&&si<=h)
            {
                si++;
            }
            while(a[ei]>pivot&&ei>=l)
            {
                ei--;
            }
            if(si<ei)
            {
                int temp = a[si];
                a[si]=a[ei];
                a[ei]=temp;
            }
        }
        a[l]=a[ei];
        a[ei]=pivot;
        quick_sort(a,l,ei-1);
        quick_sort(a,ei+1,h);
    }
    else if(size<=10&&size>0){
        int si = l;
        while(si<h)
        {
            int j = si+1;
            int temp = a[j];
            while(a[j-1]>temp&&j>l)
            {
                a[j]=a[j-1];
                j--;
            }
            a[j]=temp;
            si++;
        }
    }
}
int main()
{
    int a[] ={10,2,3,13,5,12,67,8,12,4,2,1,4,7};
    quick_sort(a,0,13);
}