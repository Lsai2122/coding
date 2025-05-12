#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
} *head=NULL;
void insert_at_end(int data){
    struct node * new_node = malloc(sizeof(struct node));
    new_node->data=data;
    new_node->next=NULL;
    if(head==NULL){
        head=new_node;
    }
    else{
         struct node * temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
}
int main(){
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);
}