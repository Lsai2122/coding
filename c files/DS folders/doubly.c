#include<stdio.h>
#include<stdlib.h>
struct node{
    int n;
    struct node * next;
    struct node * prev;
}*head =NULL,*tail =NULL;
void insert_at_end(int data){
    struct node * new_node = malloc(sizeof(struct node));
    new_node->n = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if(head==NULL || tail ==NULL){
        head = new_node;
        tail = new_node;
    }
    else{
        tail ->next = new_node;
        new_node->prev = tail;
        tail =new_node;
    }
}
void printdll(){
    struct node* temp = head;
    while(temp !=NULL){
        printf("%d,",temp -> n);
        temp = temp ->next;
    }
    printf("\n");
}
int main(){
    int flag=1;
    while(flag==1){
        int n;
        printf("1)add elemetn to ll\n2)print all elemets\n3)insert at i\n4)del at end\n5)end\n");
        scanf("%d",&n);
        switch(n){
            case 1:{
                int a;
                printf("Enter the element: ");scanf("%d",&a);
                insert_at_end(a);
                break;
            }
            case 2:{
                printdll();
                break;
            }
            /*case 3:{
                int i;
                printf("Give index i: ");scanf("%d",&i);
                int a;
                printf("give data : ");scanf("%d",&a);
                insert_at_i(a,i);
                break;
            }
            case 4:{
                del_at_end();
                break;
            }*/
            case 5:{
                flag=0;
                break;
            }
        }
    }
}