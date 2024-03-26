#include<stdio.h>
#include<stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* head=NULL;

void insertNode(int value) 
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    printf("Element inserted successfully!\n");
}
void deleteNode(int value) 
{
    struct Node *current=head,*prev=NULL;

    while(current!=NULL&&current->data!=value) 
	{
        prev=current;
        current=current->next;
    }
    if(current==NULL) 
	{
        printf("Element not found\n");
        return;
    }
    if(prev==NULL)
        head=current->next;
    else
        prev->next=current->next;
    printf("Element deleted successfully\n");
}
void searchNode(int value) 
{
    struct Node* current=head;
    while(current!=NULL) 
	{
        if(current->data==value) 
		{
            printf("Element found\n");
            return;
        }
        current=current->next;
    }
    printf("Element not found\n");
}
void displayList() 
{
    struct Node* current=head;
    if (current==NULL) 
	{
        printf("List is empty.\n");
        return;
    }
    printf("Elements in the list: ");
    while(current!=NULL) 
	{
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}
int main() 
{
    int choice, value;
    do {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) 
		{
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertNode(value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                printf("Enter the value to search: ");
                scanf("%d", &value);
                searchNode(value);
                break;
            case 4:
                displayList();
                break;
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice!=0);
    return 0;
}