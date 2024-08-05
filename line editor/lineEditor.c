#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void loadFileToBuffer(FILE *fp);
void saveDataToFile(FILE *fp);
void insert(int pos);
void display();
void delete(int pos);
void update(int pos);

FILE *fp;
int flag = 0;

typedef struct buffer
{
    char line[100];
    struct buffer *link;
} buffer;

buffer *head = NULL;
buffer *tail = NULL;
buffer *ptr = NULL;
buffer *prev = NULL;
buffer *next = NULL;
buffer *temp = NULL;

void insert(int pos)
{
    char str[100];
    int i = 1;
    printf("Add new line: ");
    scanf("%[^\n]s", str);
    buffer *new = (buffer *)malloc(1 * sizeof(buffer));
    strcpy(new->line, str);
    new->link = NULL;
    ptr = head;
    if (head == NULL)
    {
        head = new;
        return;
    }
    if (pos == 1)
    {
        new->link = head;
        head = new;
        return;
    }
    while (i < pos - 1 && ptr != NULL)
    {
        ptr = ptr->link;
        i++;
    }
    new->link = ptr->link;
    ptr->link = new;
}

void delete(int pos)
{
    ptr = head;
    int i = 1;
    if (head == NULL)
    {
        printf("file is empty\n");
        return;
    }

    if (ptr->link == NULL)
    {
        head = NULL;
        return;
    }

    if (pos == 1)
    {
        head = head->link;
        return;
    }

    while (i < pos - 1 && ptr != NULL)
    {
        ptr = ptr->link;
        i++;
    }
    ptr->link = ptr->link->link;
}

void update(int pos)
{
    ptr = head;
    int i = 1;
    char newstr[100];
    printf("Add new changed line: ");
    scanf("%[^\n]s", newstr);

    if (head == NULL)
    {
        printf("file is empty\n");
        return;
    }
    while (i < pos && ptr != NULL)
    {
        ptr = ptr->link;
        i++;
    }
    strcpy(ptr->line, newstr);
    if (pos == 1)
    {
        strcpy(ptr->line, newstr);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("file is empty right now!!\n");
    }
    ptr = head;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->line);
        ptr = ptr->link;
    }
    printf("\n");
}

void loadFileToBuffer(FILE *fp)
{
    char str[100];
    while (fgets(str, sizeof(str), fp) != NULL)
    {
        buffer *new = (buffer *)malloc(sizeof(buffer));
        new->link = NULL;
        strcpy(new->line, str);
        if (head == NULL)
        {
            head = new;
            tail = head;
        }
        else
        {
            tail->link = new;
            tail = new;
        }
    }
}

void saveDataToFile(FILE *fp)
{
    temp = head;
    while (temp != NULL)
    {
        fprintf(fp, "%s\n", temp->line);
        temp = temp->link;
    }
}

void menuDriven()
{
    printf("\n1-insert text line\n");
    printf("2-delete text line\n");
    printf("3-update text line\n");
    printf("4-display file content\n");
    printf("0-exit\n");
    printf("\nenter your choice\n");

    int choice, pos;
    scanf("%d", &choice);
    printf("\n");
    fflush(stdin);
    switch (choice)
    {
    case 1:
        printf("enter the postion of line : ");
        scanf("%d", &pos);
        fflush(stdin);
        insert(pos);
        break;

    case 2:
        printf("enter the postion of line : ");
        scanf("%d", &pos);
        fflush(stdin);
        delete (pos);
        break;

    case 3:
        printf("enter the postion of line : ");
        scanf("%d", &pos);
        fflush(stdin);
        update(pos);
        break;

    case 4:
        display();
        break;

    case 0:
        fclose(fp);
        flag = 1;
        break;
    }
}

int main(int argc, char *argv[])
{
    int choice;
    char ch;
    char str[100];
    int arguement = argc;
    if (arguement == 1)
    {
        printf("New file is created 'file.txt'\n");
        fp = fopen("file.txt", "w+");
        printf("file.txt is open\n");
        printf("file is empty now\n");
    }
    if (arguement == 2)
    {
        fp = fopen(argv[1], "a+");
        if (fp != NULL)
        {
            printf("file open\n");
            loadFileToBuffer(fp);
        }
        if (fp == NULL)
        {
            printf("\nthis name file not exists :\n");
            fp = fopen(argv[1], "w+");
            printf("Creating a file and open with same name\n");
        }
    }
    // if (arguement == 3)
    // {
    //     char str[100];
    //     strcpy(str, argv[2]);
    //     strcat(str, "\\");
    //     strcat(str, argv[1]);
    //     fp = fopen(str, "r+");
    //     if (fp == NULL)
    //     {
    //         printf("\nthis name file not exists :\n");
    //         fp = fopen(argv[1], "w+");
    //         printf("Creating a file and open with same name\n");
    //     }
    //     if (fp != NULL)
    //     {
    //         printf("file open\n");
    //         loadFileToBuffer(fp);
    //     }
    // }
    if (arguement > 3)
    {
        printf("\nmore than three arguement\n");
        exit(0);
    }
    while (1)
    {
        menuDriven();
        if (flag)
        {
            break;
        }
    }
    fclose(fp);
    if (arguement == 1)
    {
        fp = fopen("file.txt", "r+");
        saveDataToFile(fp);
        printf("\nAll the data saved into file\n");
    }

    if (arguement == 2)
    {
        fp = fopen(argv[1], "w");
        saveDataToFile(fp);
        printf("\nAll the data saved into file\n");
    }
    // if(arguement==3)
    // {
    //     fp = fopen(argv[1], "w");
    //     saveDataToFile(fp);
    //     printf("\nAll the data saved into file\n");
    // }
    return 0;
}