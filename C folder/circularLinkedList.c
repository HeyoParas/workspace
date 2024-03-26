#include<stdio.h>
#include<stdlib.h>
void beginsert(int);
void endinsert(int);
void posinsert(int,int);
void begdelete();
void enddelete();
void posdelete(int);
void display();

struct node
{
    int data;
    struct node* next;
};
struct node*head =NULL;

int main ()
{
    int ch,pos,item;
    printf("1: beginsert\n2:endinsert\n3:posinsert\n4:begdelete\n5:enddelete\n6:posdelete\n7:display\n8:exit\n");
    do
    {
       printf("enter the choice:");
       scanf("%d",&ch);

       switch (ch)
       {
       case 1:
       printf("enter the item to insert at begin of list\n");
       scanf("%d",&item);
       beginsert(item);
       break;

       case 2:
       printf("enter the item to insert at last of list\n");
       scanf("%d",&item);
       endinsert(item);
       break;

       case 3:
       printf("enter the postion where to insert node in the list\n");
       scanf("%d",&pos);
       printf("enter the item to insert in list\n");
       scanf("%d", &item);
       posinsert(item,pos);
       break;

       case 4:
       begdelete();
       break;

       case 5:
       enddelete();
       break;
        
       case 6:
       printf("enter the position of deletion of node\n");
       scanf("%d",&pos);
       posdelete(pos);
       break;

       case 7:
       display();
       break;

       case 0:
       printf("exit");
       exit(0);
       
       default:
       printf("invalid choice\n");
        break;
       }
    }
     while (ch!=0);
    return 0;
}
void beginsert(int item)
{
    struct node* n= malloc(sizeof(struct node));
    n->data=item;
    n->next=head;

    if(head==NULL)
    {
        n->next=n;
    }
    else{
        struct node* temp =head;
        while(temp->next != head)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
    head =n;
    display();
}

void display ()
{
    struct node *temp;
    temp = head;
    if(temp==NULL)
    {
        printf("linked list is empty\n");
        return;
    }
    printf("Linked list is :");
   do
   {
    printf("%d-%d->",temp->data,temp->next);
    temp=temp->next;
   } while (temp!=head);
    
}

void endinsert(int item)
{
    struct node* n=malloc(sizeof(struct node));
    struct node* temp=head;
    n->data= item;
    n->next=head;
    if(temp=NULL)
    {
        n->next=n;
        head=n;
        display();
        return;
    }
}
void posinsert(int item , int pos)
{
    struct node* n= malloc(sizeof(struct node));
    struct node* temp = head;
    n->data=item;
    n->next=head;
    if(pos==1)
    {
        beginsert(item);
        return;
    }
    for(int i=1;i<pos-1;i++)
    {
        temp =temp->next;
        if(temp==head)
        {
            printf("invalid position\n");
            return;
        }
    }
    n->next = temp->next;
    temp->next=n;
    display();
}

void begdelete()
{
    struct node* temp = head;   
    if(temp == NULL)
    {
        printf("Linked list already empty\n");
    }
    if(temp->next == head)
    {
        head==NULL;
    }
    else{
        while(temp->next !=head)
        {
            temp=temp->next;
        }
        temp->next = head->next;
        head = head-> next;
    }
    display();
}

void enddelete ()
{
    struct node* temp =head;
    if(temp==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    if(temp->next == temp)
    {
        head = NULL;
    }
    else
    {
        while(temp->next->next != head)
        {
            temp=temp->next;
        }
        temp->next =head;
    }
    display();
}

void posdelete (int pos)
{
    struct node* temp = head;
    if(pos==1)
    {
        begdelete();
        return;
    }
    if(head == NULL && pos!=1)
    {
        printf("Invalid postion\n");
        return;
    }
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
        if(temp->next == head)
        {
            printf("Invalid postion \n");
            return ;
        }
    }
    temp->next=temp->next->next;
    display();

}