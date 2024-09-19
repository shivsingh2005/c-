#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;
node *takeinput(int n)
{
    node *head,*temp,*p;
    int i;
    for(i=0;i<n;i++){
        temp=(node*)malloc(sizeof(node));
        printf("enter data %d  ",i+1);
        scanf("%d",&temp->data);
        temp->next=NULL;
        temp->prev=NULL;
        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            p=head;
            while(p->next!=NULL)
              {
                p=p->next;
                
              }
            p->next=temp;
            temp->prev=p;
          
        } 
  
    }
    return head;
}
void print(node *head){
    node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("EOL \n");
}
node *insertatith(node *head,int data,int i){
    node *temp,*p;
    temp=(node*)malloc(sizeof(node));
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    if(i==1)  // insert at head ka program
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
      
    }
  else{     // insert at ith ka program
    p=head;
    for(int j=1;j<i-1;j++){
      p=p->next;
      
    }
    temp->next=p->next;
    temp->prev=p;
    p->next=temp;
    temp->next->prev=temp;
    
  }
  return head;
}
    node *deleteAtith(node *head,int i)
{
  node *p=head;
  if(i==1){
    head=head->next;
    head->prev=NULL;
    free(p);
  }
  else{
    for(int j=1;j<i-1;j++)
      {
        p=p->next;
        
      }
    node *q=p->next;
    p->next=q->next;
    q->next->prev=p;
    free(q);
  }
  return head;

}
int main() {
    node *head;
    head=takeinput(5); 
    print(head);
    head=insertatith(head,5,2);
    print(head);

   return 0;
}
