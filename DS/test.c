/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include<stdio.h>
int bina_search(int* arr,int n, int si,int ei)
{
    if(si<ei)
    {
        if(n<arr[(si+ei)/2])
        {
            return bina_search(arr,n,si,(si+ei)/2-1);
        }
        else if(n>arr[(si+ei)/2])
        {
            return bina_search(arr,n,(si+ei)/2+1,ei);
        }
        else{
            return (si+ei)/2;
        }

    }
    return -1;
}
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int a[2];
    a[0]=bina_search(nums,target,0,numsSize-1);
    if(a[0]==-1)
    {
        a[1]=-1;
        return a;
    }
    while(nums[a[0]-1]==nums[a[0]]&&a[0]>=0)
    {
        a[0]--;
    }
    while(nums[a[0]]==nums[a[1]+1]&&a[1]<=numsSize-1)
    {
        a[1]++;
    }
    return a;
}
int main()
{
    int a[6]={5,7,7,8,8,10};
    int b[2];
    b[0]=0;
    b[1]=0;
    searchRange(a,6,8,b);
    printf("%d %d",b[0],b[1]);
    return 0;
}