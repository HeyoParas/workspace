    while (ptr != NULL)
    {
        printf("%s\n", ptr->line);
        ptr = ptr->link;
    }
    printf("\n");
}

// void display_file_data(FILE *fp)
// {
//     char str[100];
//     while (fgets(str, sizeof(str), fp) != NULL)
//     {
//         printf("%s", str);
//     }
// }

void Load_file_to_buffer(FILE *fp)
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