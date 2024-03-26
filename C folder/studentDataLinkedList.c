#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student{
	int roll_no,marks[5];
	char course[20],name[20];
};
struct node
{
	struct student entry;
	struct node* next;
};
struct node *head;
void listSort(){
	struct node *strt=head;
	struct node *ptr1=head;
	int i,temp;
	char str[20];
	if(head->next==NULL)
	   return ;
	while(strt!=NULL)
	{
		int flag=0;
		ptr1=head;
		while(ptr1->next!=NULL)
		{
			if(ptr1->entry.roll_no>ptr1->next->entry.roll_no)
			{
				temp=ptr1->entry.roll_no;
			    ptr1->entry.roll_no=ptr1->next->entry.roll_no;
			    ptr1->next->entry.roll_no=temp;
			    strcpy(str,ptr1->entry.course);
			    strcpy(ptr1->entry.course,ptr1->next->entry.course);
			    strcpy(ptr1->next->entry.course,str);
			    strcpy(str,ptr1->entry.name);
			    strcpy(ptr1->entry.name,ptr1->next->entry.name);
			    strcpy(ptr1->next->entry.name,str);
			    for(i=0;i<5;i++)
			    {
			    	temp=ptr1->entry.marks[i];
			        ptr1->entry.marks[i]=ptr1->next->entry.marks[i];
		    	    ptr1->next->entry.marks[i]=temp;
				}
			}
			ptr1=ptr1->next;
		}
	    strt=strt->next;
	} 
} 
struct student intialise(struct node st){
	int i;
	struct node *temp=head;
	printf("enter name:");
	scanf("%s",st.entry.name);
	printf("enter course:");
	scanf("%s",st.entry.course);
	printf("enter roll no:");
	scanf("%d",&st.entry.roll_no);
	while(st.entry.roll_no<=0){
    	if(st.entry.roll_no<=0)
        {
               printf("roll no should be > 0\nenter again roll no :",st.entry.roll_no);
            scanf("%d",&st.entry.roll_no);
    	}
	}
	while(temp!=NULL)
	{
	    if(st.entry.roll_no==temp->entry.roll_no || st.entry.roll_no<=0)
        {
        	printf("roll no %d already filled\nenter again roll no :",st.entry.roll_no);
        	scanf("%d",&st.entry.roll_no);
        	temp=head;
     	}
     	else
     		temp=temp->next;
    }
	printf("enter marks\n");
	printf("marks of 5 subjects \n");
	for(i=0;i<5;i++){
		printf("subject %d. ",i+1);
	    scanf("%d",&st.entry.marks[i]);
    }
	return st.entry;
}
void display(){
	int i,j;
	if(head==NULL)
	{
		printf("list is empty");
		return;
	}
	struct node* temp=head;
	while(temp!=NULL)
	{
		printf("Name : %s\tCourse : %s\tRoll no : %d\n",temp->entry.name,temp->entry.course,temp->entry.roll_no);
		printf("Marks of 5 subjects :\n");
		for(i=0;i<5;i++){
			printf("subject %d = ",i+1);
			printf(" %d ,\t",temp->entry.marks[i]);
    	}
    	temp=temp->next;
	    printf("\n");
	}

}
void insertatlast(struct node s){
	int i;
	struct node *n=(struct node*)malloc(sizeof(struct node));
	if(head==NULL)
	{
		n->entry.roll_no=s.entry.roll_no;
    	strcpy(n->entry.name,s.entry.name);
    	strcpy(n->entry.course,s.entry.course);
    	for(i=0;i<5;i++){
    	    n->entry.marks[i]=s.entry.marks[i];
        }
     	n->next=head;
    	head=n;	
	}
	struct node* temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
	temp=temp->next;
	n->entry.roll_no=s.entry.roll_no;
	strcpy(n->entry.name,s.entry.name);
	strcpy(n->entry.course,s.entry.course);
	for(i=0;i<5;i++){
    	n->entry.marks[i]=s.entry.marks[i];
    }
    temp->next=NULL;
	printf("\nEntry Successfully Completed\n");
}
int deleteatpos(int r){
	if(head==NULL)
	{
		printf("empty linked list\n");
		return 2;
	}
	if(head->next==NULL && head->entry.roll_no==r)
	{
		head=NULL;
		printf("\nStudent data deleted\n");	    
		return 2;
	}
	if(head->entry.roll_no==r)
	{
		head=head->next;
		return 1;
	}
	struct node *temp=head;
	while(temp->next!=NULL)
	{
		if(temp->next->entry.roll_no==r)
		{
			temp->next=temp->next->next;
			return 1;
		}
		temp=temp->next;
	}
    return 0;
}
int update(int r){
	int i;
	if(head==NULL)
	{
		printf("empty linked list\n");
		return 2;
	}
	struct node *temp=head;
	while(temp!=NULL)
	{
		if(temp->entry.roll_no==r)
		{
			struct node *temp2=head;
        	printf("enter name:");
        	scanf("%s",temp->entry.name);
         	printf("enter course:");
        	scanf("%s",temp->entry.course);
         	printf("enter roll no:");
         	scanf("%d",&temp->entry.roll_no);
        	while(temp->entry.roll_no<=0){
             	if(temp->entry.roll_no<=0)
                {
                    printf("roll no should be > 0\nenter again roll no :",temp->entry.roll_no);
                    scanf("%d",&temp->entry.roll_no);
            	}
        	}
        	while(temp2!=NULL)
        	{
         	    if(temp!=temp2 && (temp->entry.roll_no==temp2->entry.roll_no || temp->entry.roll_no<=0))
                {
                 	printf("roll no %d already filled\nenter again roll no :",temp->entry.roll_no);
                 	scanf("%d",&temp->entry.roll_no);
                	temp2=head;
            	}
            	else
             		temp2=temp2->next;
           }
        	printf("enter marks\n");
         	printf("marks in 5 subjects \n");
         	for(i=0;i<5;i++){
        		printf("%d. ",i+1);
        	    scanf("%d",&temp->entry.marks[i]);
            }
            return 1;
     	}
        	temp=temp->next;
    }
    return 0;
}
int main(){
	int i,ch,choice,pos;
	struct node st;
	do
	{
		printf("\n1. add new student :\n");
		printf("2. remove student :\n");
		printf("3. update student :\n");
		printf("4. display the elements :\n");
	    printf("-> other keywords for exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				st.entry=intialise(st);
				insertatlast(st);
			    listSort(); 
			    display();
				break;
			
			case 2:
				printf("Enter roll no :");
				scanf("%d",&pos);
				pos=deleteatpos(pos);
				if(pos==1){
				    printf("\nStudent data deleted\n");
				    display();
				}
				else if(pos==0)
				    printf("\nStudent not found\n");
				break;
			case 3:
				printf("Enter roll no :");
				scanf("%d",&pos);
				pos=update(pos);
				if(pos==1){
				    printf("\nStudent data Updated\n");
				    display();
				}
				else if(pos==0)
				    printf("\nStudent not found\n");
				break;
			case 4:
				display();
				break;
			default:
				printf("Press Enter For Exit");
				exit (1);
		}
	}while(choice>0 && choice<=9);
	return 0;
}
