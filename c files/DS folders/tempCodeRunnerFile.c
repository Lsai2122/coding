#include <stdio.h>
int main() {
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
    	int n,hp;
    	scanf("%d %d",&n,&hp);
    	unsigned int arr[n];
    	for(int j=0;j<n;j++)
    	{
    	    scanf("%ld",&arr[j]);
    	}
    	unsigned int an=0;
    	for(int j=0;j<n-1;j++)
    	{
    	    unsigned int m=0;
    	    for(int k=0;k<n;k++)
    	    {
        	    if(arr[m]<arr[k])
        	    {
        	        m = j;
        	    }
    	    }
    	    if(an<arr[m]+(hp*(j)))
    	    {
    	        an = arr[m]+(hp*(j));
    	    }
    	    arr[m]=0;
    	}
    	printf("%u\n",an);
	}
	
}

