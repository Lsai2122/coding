#include<stdio.h>
int bina_search(int a[],int l,int h,int c)
{
    if(l<=h)
    {
        int mid = (l+h)/2;
        if(c<a[mid])
        {
            return bina_search(a,l,mid-1,c);
        }
        else if(c>a[mid])
        {
            return bina_search(a,mid+1,h,c);
        }
        else
        {
            return mid;
        }
    }
    else{
        return -1;
    }
}
int main()
{
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int k,c;
    printf("give k ");
    scanf("%d",&k);
    printf("Enter c ");
    scanf("%d",&c);
    int n=sizeof(a)/sizeof(a[0]);
    int m = bina_search(a,0,n-1,c);
    k = k%n;
    printf("%d",(m+k)%n);
}