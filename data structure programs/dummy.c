/*C Program to perform following operation on unsorted linked ist:
1.Insert a node at beginning of linked list
2.Insert a node at end of linked list
3.Search a node in linked list
4.Delete a node from linked list
5.Display values of the nodes*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* link;
};
struct node* head=NULL;
void insAtBeg(int item)
{
    struct node *temp=head;
    struct node* new_node=temp;
    new_node=(struct node*)malloc(sizeof(new_node));
    if(head==NULL)
    {
        new_node->info=item;
        new_node->link=NULL;
        head=new_node;
    }
    else
    {
        new_node->info=item;
        new_node->link=head;
        head=new_node;

    }
}
void insAtEnd(int item)
{
    struct node *temp=head;
    struct node* new_node=temp;
    new_node=(struct node*)malloc(sizeof(new_node));
    if(head==NULL)
    {
        insAtBeg(item);
    }
    else 
    {
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        temp->link=new_node;
        new_node->info=item;
        new_node->link=NULL;
    }
}
int search_node(int item)
{
    struct node *temp=head;
    int pos=1;
    if(temp==NULL)
    {
        printf("\nLinked List is empty");
    }
    while(temp!=NULL)
    {
        if(temp->info==item)
        {
            //pos=pos+1;
            //printf("\nItem found at position %d",pos);
            break;
        }
        else 
        {
            pos=pos+1;
            temp=temp->link;
        }
    }
    if(temp==NULL)
    {
        printf("\nItem not found in linked list");
    }
    else
    {
        printf("\nItem found at position %d",pos);
        return pos;
    }
}
void del_node(int item)
{
    struct node *temp=head;
    int pos;
    if(temp==NULL)
    {
        printf("\nLinked list is empty");
    }
    else 
    {
       // pos=search_node(item);
        printf("\nElement deleted is=%d",temp->info);
        temp=temp->link;
    }
}
void display()
{
    struct node *temp=head;
    if(head==NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        printf("\nNodes in linked list: ");
        while(temp!=NULL)
        {
            printf("%d ",temp->info);
            temp=temp->link;
        }
        printf("\n");
    }
}
int main()
{
    int choice,item;
    while (1)
    {
        printf("\nEnter 1: Insert a node at beginning of linked list\nEnter 2:Insert a node at end of linked list\nEnter 3:Search a node in linked list\nEnter 4:Delete a node from linked list\nEnter 5:Display values of the nodes\nEnter 6 to Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter the item to insert in beginning: ");
                scanf("%d",&item);
                insAtBeg(item);
                break;
            case 2:
                printf("\nEnter the item to insert at end: ");
                scanf("%d",&item);
                insAtEnd(item);
                break;
            case 3:
                printf("\nEnter the item to search: ");
                scanf("%d",&item);
                search_node(item);
                break;
            case 4:
                printf("\nEnter the item to delete: ");
                scanf("%d",&item);
                del_node(item);
                break;
            case 5:
                printf("\nDisplay in linked list");
                display();
                break;
            case 6:
                printf("\nExit");
                exit(0);
                break;
            default:
                printf("\nYou entered wrong choice");
                break;
        }
    }
    return 0;
}