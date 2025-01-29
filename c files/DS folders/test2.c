#include <stdio.h>
#include<string.h>
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	    char a[]="ADVITIYA";
	    char s[9];
	    scanf("%s",s);
	    int count =0;
	    int k;
	    for(int j=0;j<7;j++)
	    {
	        if(a[j]>s[j])
	        {
	            count+=a[j]-s[j];
	        }
	        else if(a[j]<s[j])
	        {
	            k = a[j]-s[j]+26;
	            count+=k;
	        }
	    }
	    printf("%d",k);
	}
}

