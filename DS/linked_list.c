#include<stdio.h>
#include<stdlib.h>
struct node{
    int n;
    struct node* next;
};
struct node* head;
int counter()
{
    struct node* temp = head;
    if(head==NULL){return 0;}
    else if(head->next==NULL){return 1;}
    int count=1;
    while(temp->next==NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void add(int n,int i)
{
    /*indexing from 0*/
    struct node* temp = head;
    /*counting the number of nodes*/
    int count = counter();
    if(i==0&&count==0)
    {
        head = (struct node*)malloc(sizeof(struct node));
    }
    else if(i==0)
    {
        struct node* nnode=malloc(sizeof(struct node));
        nnode->next=head;
        nnode->n=n;
        head = nnode;
    }
    else if(i<count)
    {
        for(int j=0;j<i-1;j++)
        {
            temp=temp->next;
        }
        struct node* nnode = malloc(sizeof(struct node));
        nnode->n=n;
        nnode -> next=temp->next;
        temp->next = nnode;
    }
    else{
        printf("wrong index the available indexes are %d",count-1);
    }
}
void delete(int i)
{
     /*indexing from 0*/
     struct node* temp = head;
     /*counting the number of nodes*/
     int count = counter();
     if(i==0)
     {
        head = temp->next;
        free(temp);
     }
     if(i<count)
     {
        for(int j=0;j<i-1;j++)
        {
            temp=temp->next;
        }
        struct node* a = temp->next;
        temp->next=a->next;
        free(a);
     }
     else{
        printf("wrong index the available indexes are %d",count-1);
     }
}
void print(int i)
{
     /*indexing from 0*/
     struct node* temp = head;
     /*counting the number of nodes*/
     int count = counter();
     if(i==count)
     {
        for(int j=0;j<count;j++)
        {
            printf("%d ",temp->n);
            temp=temp->next;
        }
     }
     else{
        for(int j=0;j<i;j++)
        {
            temp = temp->next;
        }
        printf("%d",temp->n);
     }
}
int main()
{
    head = malloc(sizeof(struct node));
    head->n=2;
    
}