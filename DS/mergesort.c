#include<stdio.h>
void merge_sort(int a[],int l,int h)
{
    if(l<h)
    {
        merge_sort(a,l,(l+h)/2);
        merge_sort(a,(l+h)/2+1,h);
    }
    int mid = (l+h)/2;
    int si=l;
    int s1=mid-si+1;
    int s2 = h-mid;
    int temp1[s1];
    int temp2[s2];
    for(int i=0;i<mid-si+1;i++)
    {
        temp1[i]=a[i+si];
    }
    for(int i=0;i<h-mid;i++)
    {
        temp2[i]=a[mid+1+i];
    }
    int k=si;
    int i=0;
    int j=0;
    while(i<s1&&j<s2)
    {
        if(temp1[i]>temp2[j])
        {
            a[k++]=temp2[j++];
        }
        else if(temp1[i]<temp2[j])
        {
            a[k++]=temp1[i++];
        }
        else{
            a[k++]=temp1[i++];
            a[k++]=temp2[j++];
        }
    }
    while(i<s1)
    {
        a[k++]=temp1[i++];
    }
    while(j<s2)
    {
        a[k++]=temp2[j++];
    }
    return;

}
int main()
{
    int a[]= {123,41,124,51,2,4,14,5,35,1,2};
    merge_sort(a,0,sizeof(a)/sizeof(a[0])-1);
    for(int i=0;i<sizeof(a)/sizeof(a[0])-1;i++)
    {
        printf("%d\n",a[i]);
    }
}