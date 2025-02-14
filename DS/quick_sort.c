#include<stdio.h>
void quick_sort(int a[],int l,int h)
{
    if(l<h)
    {
        int si = l;int pivot= a[si];int ei = h;int temp;
        while(si<ei){
            while(a[si]<=pivot && si<h)
            {
                si++;
            }
            while(a[ei]>pivot && ei>l)
            {
                ei--;
            }
            if(ei>si)
            {
                temp = a[si];
                a[si] = a[ei];
                a[ei]=temp;
            }
            
        }
        if(l<mid)
        a[l] = a[ei];
        a[ei]=pivot;
        quick_sort(a,l,ei-1);
        quick_sort(a,ei+1,h);
    }
}
int main()
{
    int a[]= {11,20,3,2,9,15,10,8};
    quick_sort(a,0,sizeof(a)/sizeof(a[0])-1);
}