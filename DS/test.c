#include<stdio.h>
int main(){
    int i,j,k,n,m,temp,x,y,z;
    printf("enter the num:");
    scanf("%d",&n);
    int a[n];
    printf("enter the %d array elements:",n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        m=i;
        for(j=i+1;j<n;j++){
            if(a[m]>a[j])
            m=j;
        }
        if(m!=i){
            temp=a[m];
            a[m]=a[i];
            a[i]=temp;
        }
    }
    for(i=0;i<n-2;i++){
        for(j=i+1;j<n-1;j++){
            for(k=j+1;k<n;k++){
                if((a[i]+a[j]+a[k])==0){
                    if(a[i]!=x||a[j]!=y||a[k]!=z)
                    printf("(%d,%d,%d)",a[i],a[j],a[k]);
                    x=a[i];
                    y=a[j];
                    z=a[k];
                }
            }
        }
    }
}