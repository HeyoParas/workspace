#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
void display()
{
		if(head==NULL)
	{
		printf("linked list is empty\n");
		return;
	}
	struct node *temp = head;
printf("\n\nList elements are - \n");
while(temp!=NULL) {
  printf("%d\n",temp->data);
  temp = temp->next;
}
}
void insert(int element)
{
	struct node *n;
	n= (struct node *)malloc(sizeof(struct node));
	n->data=element;
	if(head==NULL||element<head->data)
	{
		n->next=head;
		head=n;
		display();
		return;
	}
	struct node*temp=head->next;
	struct node*par=head;
	while(temp!=NULL)
	{
		if(element<temp->data&&par->data<element)
		{
			n->next=temp;
			par->next=n;
			display();
	        return;
		}
		else{
			par=temp;
			temp=temp->next;
		}
	}
    par->next=n;
    n->next=NULL;
    display();
}
void deletion(int element)
{
	if(head==NULL)
	{
		return;
	}
	if(head->next==NULL)
    {
    	head=NULL;
    	display();
    	return;
	}
	struct node*temp=head->next;
	struct node*par=head;
	while(temp!=NULL)
	{
		if(element==head->data)
		{
			head=head->next;
			display();
			return;
		}
		else if(element==temp->data)
		{
			par->next=temp->next;
			temp->next=NULL;
			display();
			return;
		}
		else
		{
			par=temp;
			temp=temp->next;
		}
	}
	
}
void search(int element)
{
	struct node*temp=head;
	int pos=0;
	while(temp!=NULL)
	{
		pos++;
		if(element==temp->data)
		{
			printf("element is found at position=%d\n",pos);
			return;
		}
		else
		{
			temp=temp->next;
		}
	}
	printf("no element is present in the list\n");
}
int main()
{
	int element,choice;
	while(1)
	{
		printf("1.insertion\n2.deletion\n3.search\n4.display\n5.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("enter element=");
			scanf("%d",&element);
			insert(element);
			break;
		case 2:
			printf("enter element=");
			scanf("%d",&element);
			deletion(element);
			break;
		case 3:
			printf("enter element=");
			scanf("%d",&element);
			search(element);
			break;
		case 4:
			display();
			break;
		case 5:
			exit(0);
		default:
			printf("invalid choice\n");
		}
	}
	return 0;
}


// docs.google.com/spreadsheets/d/1VmWENwqcYWTgr8vcb13rwvRMyBIYQ5YKxdiOwCM0OBU/edit#gid=1787140091