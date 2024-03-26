#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct song
{
    char song_name[20];
    char singer[20];
    char genre[20];
};
struct node
{
    struct song data;
    struct node* next;
    struct node* prev;
};
struct node* head =NULL;
struct node* head2 =NULL;

void insertsong()
{
    struct node* n=malloc(sizeof(struct node));
    struct node* temp=head;
    printf("enter the name of the song : ");
    if(head!=NULL)
    {
        while(temp!=NULL)
        {
            if(strcmp(n->data.song_name,temp->data.song_name)==0)
            {
                printf("\n song name already exist \n");
                printf("enter different song name :");
                scanf("%s",n->data.song_name);
                temp=head;
            }
            else
            temp=temp->next;
        }
    }
    printf("enter the singer name: ");
    scanf("%s",n->data.singer);
    printf("enter the genre: ");
    scanf("%s",n->data.genre);
    n->next=head;
    n->prev=NULL;
    if(head!=NULL)
    {
        head->prev=n;
    }

}
int main()
{

    return 0;
}