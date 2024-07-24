#include <stdio.h>
#include <stdlib.h>

int main() {
    int Size = 10; 
    char *str = malloc(Size * sizeof(char)); 
 
    if (str == NULL) {  
        printf("Memory not allocate\n");
        return 0;
    }

    printf("Enter a string: ");

    int c;
    int length = 0;

    while ((c = getchar()) != '\n') {
        if (length == Size - 1) {  
            Size =Size * 2;
            str = realloc(str, Size * sizeof(char)); 
            if (str == NULL) {  
                printf("Memory not allocate\n");
                return 0;
            }
        }
        str[length] = (char)c;
        length++;
    }

    str[length] = '\0'; 
    printf("Your string: %s\n", str);  
    free(str);  
    return 0;
}