#include<stdio.h>
struct node
{
    int data;
    struct node* next;
};
struct node * head;
void insertnode(int x,int pos)
{
    struct node* n=malloc(sizeof(struct node));
    n->data=x;
    if(pos==1)
    {
        n->next=NULL;
        head = n;
    }
    if(head->next!=NULL)
    {
    struct node* temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
    }
    else{
        printf("invalid location");
    }
}
void display ()
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void reverse()
{
    
}
int main()
{

    return 0;
}