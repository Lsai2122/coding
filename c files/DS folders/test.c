#include<stdio.h>
#include<stdlib.h>
int add_1(int * nums,int n){
    for(int i=0;i<n;i++){
        *(nums+i)=*(nums+i)+1;
        nums[i]=nums[i]+1;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int *nums = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        nums[i]=i;
    }
    add_1(nums,n);
}