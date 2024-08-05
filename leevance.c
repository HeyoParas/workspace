#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct storage_node {
    char data[100];
    struct storage_node *next;
} storage_node;

    FILE *fp;

storage_node *head = NULL;
storage_node *tail = NULL;

void close_program() {
    fp = fopen("f.txt","w+") ;
    storage_node* current = head ;
    while(current!=NULL)
    {
        fprintf(fp,"%s",current->data) ;
        current = current->next ;
    }
    fclose(fp) ;
    exit(0);
}

void display() {
    printf(".....................................................................\n");
    storage_node *current = head;
    while (current != NULL) {
        printf("%s", current->data);
        current = current->next;
    }
}

void storing_data(FILE *fp) {
    char ch[100];
    while (fgets(ch, sizeof(ch), fp) != NULL) {
        storage_node *newnode = (storage_node *)malloc(sizeof(storage_node));
        newnode->next = NULL;
        strcpy(newnode->data, ch);

        if (head == NULL) {
            head = newnode;
            tail = head;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
}

void createnode() {
    int ch;
    char line[100];
    printf("1 - At the end 2 - At the start: ");
    scanf("%d", &ch);
    getchar(); // Consume newline character left by scanf

    printf("Enter the line you want to add here: ");
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0'; // Remove trailing newline character

    storage_node *newnode = (storage_node *)malloc(sizeof(storage_node));
    strcpy(newnode->data, line);
    strcat(newnode->data, "\n");
    newnode->next = NULL;

    if (ch == 1) {
        if (head == NULL) {
            head = newnode;
            tail = head;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    } else if (ch == 2) {
        newnode->next = head;
        head = newnode;
        if (tail == NULL) {
            tail = newnode;
        }
    } else {
        printf("Wrong input! ");
        free(newnode);
        return;
    }

    display();
}

void deletenode() {
    int ch;
    printf("1 - Delete from start 2 - Delete from end: ");
    scanf("%d", &ch);
    getchar(); // Consume newline character left by scanf

    if (ch == 1) {
        if (head == NULL) {
            printf("List is empty!\n");
            return;
        }
        storage_node *temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        free(temp);
    } else if (ch == 2) {
        if (head == NULL) {
            printf("List is empty!\n");
            return;
        }
        if (head->next == NULL) {
            free(head);
            head = tail = NULL;
        } else {
            storage_node *current = head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            free(tail);
            tail = current;
            tail->next = NULL;
        }
    } else {
        printf("Wrong choice!\n");
        return;
    }

    display();
}

void update_line() {
    int position;
    char newtext[100];
    storage_node *current = head;

    printf("node number : ");
    scanf("%d", &position);
    getchar();

    printf("Enter the new text here: ");
    fgets(newtext, sizeof(newtext), stdin);

    int len = strlen(newtext);
    if (len > 0 && newtext[len - 1] == '\n') {
        newtext[len - 1] = '\0';
    }
    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of range!\n");
        return;
    }
    strcpy(current->data, newtext);
    strcat(current->data, "\n");

    display();
}

void update_content_in_line() {
    int position;
    char oldword[50], newword[50];
    storage_node *current = head;

    printf("Node number: ");
    scanf("%d", &position);
    getchar();

    printf("Enter the word you want to replace: ");
    scanf("%s", oldword);
    getchar();
    
    printf("Enter the new word: ");
    scanf("%s", newword);
    getchar();

    for (int i = 1; i < position && current != NULL; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Position out of range!\n");
        return;
    }

    char *pos = strstr(current->data, oldword);
    if (pos != NULL) {
        char newstr[100];
        int orgnl = pos - current->data;
        int old_len = strlen(oldword);
        int new_len = strlen(newword);

        strncpy(newstr, current->data, orgnl);
        newstr[orgnl] = '\0';
        strcat(newstr, newword);
        strcat(newstr, pos + old_len);

        strcpy(current->data, newstr);
    } else {
        printf("Word not found.\n");
    }

    display();
}

void menu() {
    printf("\n1 - Create a new node (beginning or end)\n");
    printf("2 - Delete a node\n");
    printf("3 - Replace\n");
    printf("4 - Display\n");
    printf("5 - Replace a specific word\n");
    printf("6 - Exit\n");
}

int main(int argc, char *argv[]) {
    //..................................................................................//
    if (argc == 1) {
        fp = fopen("file.txt", "w+");
    } else if (argc == 2) {
        fp = fopen(argv[1], "r+");
        if (fp != NULL) {
            storing_data(fp);
        } else {
            fp = fopen(argv[1], "w+");
            printf("New file created successfully\n");
        }
    } else if (argc == 3) {
        char newfile[100];
        strcpy(newfile, argv[2]);
        strcat(newfile, argv[1]);
        fp = fopen(newfile, "w+");
    } else {
        printf("Wrong number/order of arguments!\n");
        exit(0);
    }

    if (fp == NULL) {
        printf("Failed to open file!\n");
        exit(0);
    }
//......................................................................................//
    int choice;
    int ch;
    do {
        menu();
        printf("Enter your choice here: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character left by scanf

        switch (choice) {
            case 1:
                createnode();
                break;
            case 2:
                deletenode();
                break;
            case 3:
                update_line() ;
                break;
            case 4:
                display();
                break;
            case 5:
                update_content_in_line() ;
            case 6:
                close_program();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}