#include<string.h>
#include<stdio.h>
int subarray(char* s,int l,int h,int max)
{
    if(l<h)
    {
        max = subarray(s,l+1,h,max);
    }
    int a=1;
    for(int i=l;i<=h-1;i++)
    {
        for(int j =i+1;j<=h;j++)
        {
            if(a==0)
            {
                break;
            }
            if(s[i]==s[j])
            {
                a=0;
            }

        }
        if(a==0)
        {
            break;
        }
    }
    if(a==1&&max<h-l+1)
    {
        return h-l+1;
    }
    return max;
}
int lengthOfLongestSubstring(char* s) {
    int size = strlen(s);
    int max = subarray(s,0,size-1,0);
    return max;
}
