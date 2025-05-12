#include<stdio.h>
#define max 4
void push(int data,int stack[],int *top){
    if(*top==max-1){
        printf("pora puski");
    }
    else{
        stack[++*top]=data;
    }
}
int pop(int stack[],int *top){
    if(*top==-1){3
        printf("em ledh ada");
        return -1;
    }
    else{
        return stack[(*top)--];
    }
}
int main(){
    int stack[max];
    int top =-1;
    push(1,stack,&top);
    push(2,stack,&top);
    push(3,stack,&top);
    push(4,stack,&top);
    push(5,stack,&top);
    pop(stack,&top);
    push(6,stack,&top);
    pop(stack,&top);pop(stack,&top);
    
}