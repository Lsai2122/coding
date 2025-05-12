#include<stdio.h>
#include<stdlib.h>
struct node{
    int n;
    struct node* next;
    struct node* prev;
}*head =NULL;

void insert_at_end(int data){
    struct node * new_node = malloc(sizeof(struct node));
    new_node->n=data;
    new_node->next=head;
    if(head==NULL){
        head= new_node;
    }
    else{
        struct node * temp=head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp ->next = new_node;
    }
}
void printll(){
    struct node * temp = head;
    printf("%d,",temp->n);
    temp= temp->next;
    while(temp !=head){
        printf("%d,",temp->n);
        temp= temp->next;
    }
    printf("\n");
}
void insert_at_i(int data,int i){
    struct node *temp = head;
    for(int j=0;j<i-1;j++){
        temp = temp->next;
    }
    struct node * new_node = malloc(sizeof(struct node));
    new_node->n = data;
    new_node->next = temp->next;
    temp ->next = new_node;
}
void del_at_end(){
    struct node * temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next=NULL;
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
                printll();
                break;
            }
            case 3:{
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
            }
            case 5:{
                flag=0;
                break;
            }
        }
    }
}