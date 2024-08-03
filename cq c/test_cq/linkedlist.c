#include<stdio.h>
struct node{
    int info;
    struct node* next;
};
struct node* head;

struct node* new(struct node* head,int info)
{
    return head;
}

int main (){
    int info;
    int choice;
     while (1)
    {
        printf("Menu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the element you want to insert:");
            scanf("%d",&info);
            break;
        case 2:
            printf("enter the element you want to delete");
            scanf("%d",&info);
            break;
        case 3:
            printf("display");
            scanf("%d",&info);
            break;
        default:
            break;
        }
    }
    return 0;
}