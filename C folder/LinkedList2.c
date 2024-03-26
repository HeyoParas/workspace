#include<stdio.h>
#include<stdlib.h>
struct node{
    int data ;
    struct node * next;
};
void insertAtBeg(int x,struct node* head)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data=x;
    n->next=head;
    head=n;
}
void InsertAtEnd(int x,struct node* head)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data=x;
    if(head==NULL)
    {
        head=n;
        display(head);
        return; 
    }
    struct node*temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
   
}
void InsertAtPos(int x,int pos,struct node* head)
{
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data=x;
    if(pos==1)
    {
        insertAtBeg(x,&head);
        return;
    }
    if(head==NULL && pos!=1)
    {
        printf("invalid position");
        return;
    }
    struct node *temp=head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("invalid position");
            return;
        }
    }
    n->next=temp->next;
    temp->next=n;
  
}
int deleteAtBeg(struct node* head)
{
    if(head==NULL)
    {
        printf("link list is empty");
        return;
    }
    struct node*temp=head;
    head=head->next;
    temp->next=NULL;
    return head;
}
void deleteAtEnd(struct node* head)
{
    if(head==NULL)
    {
        printf("link list is empty");
        return;
    }
    if(head->next==NULL)
    {
        head=NULL;
        return;
    }
    struct node*temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    
}
void deleteAtpos(int pos,struct node* head)
{
    if(pos==1)
    {
        deleteAtBeg(head);
        return;
    }
    if(head=NULL && pos!=1)
    {
        printf("invalid position");
        return;
    }
    struct node*temp = head;
    for(int i=1;i<pos-1;i++)
    {
        temp=temp->next;
    }
    temp->next=temp->next->next;
    temp->next->next=NULL;
   
}
void display(struct node* head)
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
int main ()
{
struct node* head;
int choice, data, pos;

    while (1)
    {
        printf("Menu\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at given postion\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from given postion\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
          switch (choice) 
        {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeg(data,&head);
                display(&head);
                printf("\n");
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                InsertAtEnd(data,&head);
                display(&head);
                printf("\n");
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position where you insert: ");
                scanf("%d", &pos);
                InsertAtPos(data,pos,&head);
                display(&head);
                 printf("\n");
                break;
            case 4:
                deleteAtBeg(&head);
                display(&head);
                 printf("\n");
                break;
            case 5:
                deleteAtEnd(&head);
                display(&head);
                 printf("\n");
                break;
            case 6:
                printf("Enter the postion from where you delete the node");
                scanf("%d", &pos);
                deleteAtpos(pos,&head);
                display(&head);
                 printf("\n");
            case 7:
                break;
                display(&head);
                 printf("\n");
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}