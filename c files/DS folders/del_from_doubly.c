#include<stdio.h>
#include<stdlib.h>
struct node {
    int n;
    struct node* next;
    struct node* prev;
}*head=NULL;
int iae(int data){
    struct node* new_node = malloc(sizeof(struct node));
    if(new_node ==NULL){
        printf("somthing went wrong");
        return 0;
    }
    new_node->n = data;
    if(head==NULL){
        head = new_node;
        new_node->next = new_node;
        new_node->prev=new_node;
    }
    else{
        new_node->next = head;
        new_node->prev = head->prev;
        head->prev->next = new_node;
        head->prev = new_node;
    }
    return 1;
}
void dae(int a,struct node *temp){
    if(temp->next !=head){
        dae(a,temp->next);
    }
    if (temp -> n==a){
        if(temp ==head){
            head = head ->next;
        }
        temp -> prev->next=temp ->next;
        temp ->next->prev = temp ->prev;
        free(temp);

    }
}
void printll(){
    struct node*temp = head->next;
    printf(",\n%d\n",head->n);
    while(temp!=head){
        printf("%d\n",temp ->n);
        temp = temp ->next;
    }
    printf("'\n");
}
int main(){
    int flag = 1;
    while(flag){
        printf("1) Add element to linked list\n2)remove a data\n3)print all elements\n4)end\n");
        int n;
        scanf("%d",&n);
        switch(n){
            case 1:{
                int a;
                scanf("%d",&a);
                iae(a);
                break;
            }
            case 2:{
                int a;
                scanf("%d",&a);
                dae(a,head);
                break;
            }
            case 3:{
                printll();
                break;
            }
            case 4:{
                flag = 0;
                break;
            }
        }
    }
}