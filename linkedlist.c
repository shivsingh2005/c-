// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    
}node;
node*  takein(int n){
node *head=NULL, *temp,*p;
int i;

for(i=0;i<n;i++){
    temp=(node*)malloc(sizeof(node));
    printf("enter %d elements of list",i);
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(head==NULL){
        head=temp;
    }
    else{
        p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=temp;
    }
}
    return head;
}
void print(node *head)
{
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
node *reverse(node* head){
    node* curr=head;
    node*prev=NULL;
    node *agla;
    while(curr!=NULL){
        
        agla=curr->next;
        curr->next=prev;
        prev=curr;
        curr=agla;
        
        
    }
    head=prev;
    return head;

    
}
void printsum(node *head){
    node* temp=head;
    int sum=0;
    while(temp!=NULL){
        sum=sum+ temp->data;
        temp=temp->next;
        
    }
    printf("%d",sum);
}
int main() {
    node* head;
    head= takein(3);
    head=reverse(head);

    print(head);
   printsum(head);
    // Write C code here
    printf("Try programiz.pro");

    return 0;
}
