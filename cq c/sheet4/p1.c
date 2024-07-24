//check palindrome or not using recursion
#include <stdio.h>
#include <string.h>
static int count=0;
int isPalindromeRecursive(char str[], int start, int end, int mid) {
    if (str[start]==str[end]) {
        count++;
        if(count==mid)
        {
            return 1;
        }
    }
    if (str[start] != str[end]) {
        return 0;
    }
    return isPalindromeRecursive(str, start + 1, end - 1,mid);
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    if (isPalindromeRecursive(str, 0, len - 1,len/2)) {
        printf("string is a palindrome.\n");
    } else {
        printf("string is not a palindrome.\n");
    }
    return 0;
}
