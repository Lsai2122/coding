#include<stdio.h>
top = -1;
int n;
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
    printf("enter length of stack : ");scanf("%d",&n);
    int stack[n];
    push(1,stack);
}