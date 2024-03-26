/*23.Write a program to perform following operations on unsorted linked list:
Insert a node at the beginning of linked list
Insert a node at the end of linked list
Search a node in linked list
Delete a node from the linked list
Display values of all the nodes*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node* link;
};
 struct node* head=NULL;
void beg_insert(int ele)
{
    if(head==NULL)
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        new->info=ele;
        new->link=NULL;
        head=new;
    }
    else{
         struct node *new=(struct node*)malloc(sizeof(struct node));
         new->info=ele;
         new->link=head;
         head=new;
    }
}
void end_insert(int element)
 {
    if(head==NULL)
    {
        beg_insert(element);
    }
    else
    {   
         struct node *new=(struct node*)malloc(sizeof(struct node));
         new->info=element;
         new->link=NULL;
         struct node* ptr=head;
         while(ptr->link!=NULL)
         {
            ptr=ptr->link;
         }
         ptr->link=new;
    }
 }
void delete(int ele)
{
    if(head==NULL)
    {
        printf("linkedlist is empty\n");
        return;
    }
    struct node *ptr=head;
    struct node *prev=head;
    int count=1;
     while(ptr!=NULL)
    {
        if(ele==ptr->info)
        {
            break;
        }
        else{
        ptr=ptr->link;
        count++;
        }
    }
    int pos=count;
    for(int i=1;i<pos-1;i++)
    {
        ptr=ptr->link->link;
        prev=prev->link;
    }
    prev->link=ptr->link;
    ptr->link=NULL;
}
void display()
 {
    struct node* temp=head;
    if(head==NULL)
    {
        printf("linklist is empty");
    }
    else{
    while(temp!=NULL)
    {
        printf("%d  ",temp->info);
        temp=temp->link;  
    }
    printf("\n");
    }
 }
int search(int ele)
{
    int pos=1;
    struct node *ptr=head;
    if(ptr==NULL)
    {
        printf("linklist is empty\n");
    }
    while(ptr!=NULL)
    {
        if(ele==ptr->info)
        {
            break;
        }
        else{
        ptr=ptr->link;
        pos++;
        }
    }
    if(ptr==NULL)
    {
        printf("element not found\n\n");
        return -1;
    }
    else
    {
       return pos;
    }
    
}
int main ()
{
    int choice;
     int ele;
    while(1)
    {
        printf("1. Insert at begin\n");
        printf("2. Insert at end\n");
        printf("3. search a node \n");
        printf("4. delete a node\n");
        printf("5. display\n");
        printf("0. exit\n");
        printf("enter the choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the element you want to insert at begin :");
            scanf("%d",&ele);
            beg_insert(ele);
            break;
            
            case 2:
            printf("enter the element you want to insert at end :");
            scanf("%d",&ele);
            end_insert(
                ele);
            break;

            case 3:
            printf("enter the element you want to search in linked list:");
            scanf("%d",&ele);
            int pos=search(ele);
            printf("element found at :%d\n",pos);
            break;

            case 4:
            printf("enter the element you want to delete from linked list:");
            scanf("%d",&ele);
            search(ele);
            break;

            case 5:
            display();
            break;

            case 0:
            exit(0);
            break;

            default :
            printf("wrong choice \n\a");
            break;

        }

    }


    return 0;
}