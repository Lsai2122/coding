#include<stdio.h>
#include<stdlib.h>
struct node{
    int n;
    struct node* next;
};
struct node* head;
void add_at_end(int n)
{
    struct node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    struct node* new_node = malloc(sizeof(struct node));
    temp ->next = new_node;
    new_node->n=n;
}
void add_at_index(int i,int n)
{
    struct node* temp = head;
    for(int j=0;j<i-1;j++)
    {
        temp = temp->next;
    }
    struct node* new_node = malloc(sizeof(struct node));
    struct node* temp1 = temp->next;
    temp->next=new_node;
    new_node->next=temp1;
}
int main()
{

    head = malloc(sizeof(struct node));
    head->n=2;
}