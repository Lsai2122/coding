#include<stdio.h>
int main(){
    char a[]="()((())))";
    int stack[sizeof(a)];
    int top=-1;
    int flag=1;
    for(int i=0;i<sizeof(a);i++){
        if(a[i]=="("){
            stack[++top]="(";
        }
        else if(a[i]==")"){
            if(stack[top]=="("){
                top--;
            }
            else{
                flag=0;
                break;
            }
        }
    }
    if(flag==1){
        printf("syntax is correct");
    }
    else{
        printf("syntax is wromg");
    }
}