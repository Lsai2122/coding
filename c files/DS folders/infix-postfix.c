#include<stdio.h>
int stack[10];
int top =-1;
int n=10;
void push(int data,int *stack){
    top++;
    if(top<n)
    {
        stack[top]=data;
    }
    else{
        printf("stack full");
    }
}
int pop(int *stack){
    if(top==-1){
        printf("Stack is empty");
    }
    else{
        return stack[top--]; 
    }
}
int main(){
    char eq[20];
    scanf("%s",eq);
    for(int i=0;eq[i]!='\0';i++){
        if(eq[i]=='+'||eq[i]=='-'||eq[i]=='*'||eq[i]=='/'){
            if(top==-1){
                push(eq[i],stack);
            }
            else if(eq[i]=='+'||eq[i]=='-'){
                printf("%c",pop(stack));
                push(eq[i],stack);
            }
            else if(eq[i]=='*'||eq[i]=='/'){
                if(stack[top]=='+'||stack[top]=='-'){
                    push(eq[i],stack);
                }
                else{
                    printf("%s",pop(stack));
                    push(eq[i],stack);
                }
            }
        }
        else{
            printf("%s",eq[i]);
        }
    }
    while(top>=0){
        printf("%c",stack[top--]);
    }
}