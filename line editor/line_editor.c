#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>

void loadFileToBuffer(FILE *fp);
void saveDataToFile(FILE *fp);
void insert(int pos);
void display();
void delete(int pos);
void update(int pos);
void changeWord(int pos, const char* oldWord, const char* newWord);


FILE *fp;
int flag = 0;
int noOfLines=0;
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
    if(pos==(noOfLines+1)||pos<=noOfLines){
    printf("Add new line: ");
    scanf("%[^\n]s", str);
    buffer *new = (buffer *)malloc(1 * sizeof(buffer));
    strcpy(new->line, str);
    strcat(new->line, "\n");
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
        noOfLines++;
        return;
    }
    while (i < pos - 1 && ptr != NULL)
    {
        ptr = ptr->link;
        i++;
    }
    new->link = ptr->link;
    ptr->link = new;
    noOfLines++;
    }
    else
    {
        printf("\n<<<<<You enter wrong postion>>>>>\n");
    }
}

void delete(int pos)
{
    ptr = head;
    int i = 1;
    if(pos<=noOfLines)
    {
    if (head == NULL)
    {
        printf("file is empty\n");
        return;
    }

    if (ptr->link == NULL)
    {
        head = NULL;
        noOfLines--;
        return;
    }

    if (pos == 1)
    {
        head = head->link;
        noOfLines--;
        return;
    }

    while (i < pos - 1 && ptr != NULL)
    {
        ptr = ptr->link;
        i++;
    }
    ptr->link = ptr->link->link;
    noOfLines--;
    }
    else
    {
        printf("\n<<<<<You enter wrong postion>>>>>\n");
    }
}

void update(int pos)
{
    ptr = head;
    int i = 1;
    char newstr[100];
    if(pos<=noOfLines)
    {
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
    strcat(ptr->line, "\n");
    
    if (pos == 1)
    {
        strcpy(ptr->line, newstr);
        strcat(ptr->line, "\n");
    }
    }
    else
    {
        printf("\n<<<<<You enter wrong postion>>>>>\n");
    }
}
void changeWord(int pos, const char* oldWord, const char* newWord)
{
    ptr = head;
    int i = 1;
    if(pos <= noOfLines)
    {
        while (i < pos && ptr != NULL)
        {
            ptr = ptr->link;
            i++;
        }
        if (ptr != NULL)
        {
            char* pos = strstr(ptr->line, oldWord);
            if (pos != NULL)
            {
                char tempStr[200];  
                int oldWordLen = strlen(oldWord);
                int newWordLen = strlen(newWord);
                int lenBeforeWord = pos - ptr->line;

                strncpy(tempStr, ptr->line, lenBeforeWord);
                tempStr[lenBeforeWord] = '\0';

                strcat(tempStr, newWord);

                strcat(tempStr, pos + oldWordLen);

                strcpy(ptr->line, tempStr);
            }
            else
            {
                printf("\n<<<<<Word not found in the specified line>>>>>\n");
            }
        }
    }
    else
    {
        printf("\n<<<<<You entered wrong line position>>>>>\n");
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
        printf("%s", ptr->line);
        ptr = ptr->link;
    }
    printf("\n");
}

void loadFileToBuffer(FILE *fp)
{
    char str[100];
    if(fp==NULL)
    {
        noOfLines=0;
    }
    else{
    while (fgets(str, sizeof(str), fp) != NULL)
    {
        buffer *new = (buffer *)malloc(sizeof(buffer));
        new->link = NULL;
        strcpy(new->line, str);
        if (head == NULL)
        {
            head = new;
            tail = head;
            noOfLines++;
        }
        else
        {
            tail->link = new;
            tail = new;
        noOfLines++;
        }
    }
    }
}

void saveDataToFile(FILE *fp)
{
    temp = head;
    while (temp != NULL)
    {
        fprintf(fp, "%s", temp->line);
        temp = temp->link;
    }
}

void menuDriven()
{
    printf("\n1-insert text line\n");
    printf("2-delete text line\n");
    printf("3-update text line\n");
    printf("4-display file content\n");
    printf("5-change substring\n");
    printf("0-exit\n");
    printf("\nenter your choice : ");

    int choice,pos;
    char oldWord[100], newWord[100];
    scanf("%d", &choice);
    printf("\n");
    fflush(stdin);
    switch (choice)
    {
    case 1:
        printf("enter the postion of line : ");
        scanf("%d", &pos);
        fflush(stdin);
        system("cls");
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
    system("cls");
        display();
        break;

    case 5:
        printf("enter the line position : ");
        scanf("%d", &pos);
        printf("enter the word to be replaced : ");
        scanf("%s", oldWord);
        printf("enter the new word : ");
        scanf("%s", newWord);
        fflush(stdin);
        system("cls");
        changeWord(pos, oldWord, newWord);
        break;

    case 0:
        fclose(fp);
        flag = 1;
        break;

    default:
    printf("wrong choice\n");
    return;
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
        fp = fopen("file.txt", "r+");
        printf("file.txt is open\n");
        printf("file is empty now\n");
        return 0;
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
    //     if (fp == NULL)
    //     {
    //         printf("\nthis name file not exists :\n");
    //         fp = fopen(argv[1], "w+");
    //         printf("Creating a file and open with same name\n");
    //     }
    //     if (fp != NULL)
    //     {
    //         printf("file open\n");
    //         fp = fopen(str, "r+");
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
        fclose(fp);
    }

    if (arguement == 2)
    {
        fp = fopen(argv[1], "w");
        saveDataToFile(fp);
        printf("\nAll the data saved into file\n");
        fclose(fp);
    }
    // if(arguement==3)
    // {
    //     fp = fopen(argv[1], "w");
    //     saveDataToFile(fp);
    //     printf("\nAll the data saved into file\n");
    //     fclose(fp);
    // }
    return 0;
}