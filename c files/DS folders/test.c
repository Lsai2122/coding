#include <stdio.h>
void quick_sort(long int arr[],long int l,long int h)
{
    long int pivot = arr[l];long int si = l;long int ei = h;
    while(si<ei)
    {
        while(arr[si]<=pivot&&si<h)
            si++;
        while(arr[ei]>=pivot&&ei>l)
            ei--;
        if(si<ei)
        {
            int temp = arr[si];
            arr[si] = arr[ei];
            arr[ei]= temp;
        }
        else
        {
            int temp = arr[l];
            arr[l] = arr[ei];
            arr[ei] = temp;
        }
    }
    if(l<h)
    {
        quick_sort(arr,l,ei-1);
        quick_sort(arr,ei+1,h);
    }
    return;
}
int main() {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
    	int n,hp;
    	scanf("%d %d",&n,&hp);
    	long int arr[n];
    	for(int j=0;j<n;j++)
    	{
    	    scanf("%ld",&arr[j]);
    	}
    	quick_sort(arr,0,n-1);
    	long int an = 0;
    	long int day = 0;
    	for(int j=n-1;j>=0;j--)
    	{
    	    if(an<arr[j]+(day*hp))
    	    {
    	        an = arr[j]+(day*hp);
    	    }
    	    day++;
            
    	}
    	printf("%ld\n",an);
	}
	
}

