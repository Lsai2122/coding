#include<stdio.h>
int main(){
    char a[]="((())(())((()))";
    int stack[sizeof(a)][2];
    int top=-1;
    for(int i=0;a[i]!='\0';i++){
        if(a[i]=='('){
            top++;
            stack[top][0]=i;
            stack[top][1]=-1;
        }
        else if(a[i]==')'){
            if(top!=-1){
                int temp = top;
                int flag=1;
                while(stack[temp][1]!=-1){
                    temp--;
                    if(temp==-1){
                        flag=0;
                        break;
                    }
                }
                if(flag!=0){
                    while(top>temp){
                        stack[top][1]=-1;
                        stack[top][0]=-1;
                        top--;
                    }
                    stack[top][1]=i;
                }
                else{
                    stack[++top][1]=-1;
                }
            }
        }
    }
    int count=0;
    int max=0;
    for(int i=0;i<=top;i++){
        if(stack[i][1]!=-1){
            count+=stack[i][1]-stack[i][0]+1;
        }
        else{
            if(max<count){
                max=count;
                count=0;
            }
        }
    }
    if(max<count){
        max=count;
    }
    printf("%d",max);
}