// 18. Write a C program to check if a number is Happy number or not.

// (A happy number for this program is defined as a process that replaces a number with the sum of the squares of its digits. This process is repeated until the number either equals 1 (indicating a "happy" ending) or the number is a single digit number other than 1 (indicating the number is not "happy")).

// For example, consider the number 23:

// First, we find the sum of the squares of its digits: (2^2) + (3^2) = 4 + 9 = 13
// For the resulting 13, we repeat the process: (1^2) + (3^2) = 1 + 9 = 10
// We do the same for 10: (1^2) + (0^2) = 1
// In the above example, we arrive at the number 1 after three processes, indicating that 23 is a happy number. 

// Example 2, consider the number 21:

// First, we find the sum of the squares of its digits: (2^2) + (1^2) = 4 + 1 = 5
// In the above example, we arrive at the number 5 after one process which is a single digit number, indicating that 21 is not a happy number.

// Sample Input 1:
// Enter a number: 32
// Sample Output 1:
// It is a Happy number.

// Sample Input 2:
// Enter a number: 41
// Sample Output 2:
// It is not a happy number.
#include<stdio.h>
int squaresum(int n)
{
    int sum =0;
    while(n)
    {
        int rem=n%10;
        sum= sum+rem*rem;
        n=n/10;
    }
    return sum;
}
int main ()
{
    int num,res,org;
    printf("enter the number :");
    scanf("%d",&num);
    org=num;
    res=squaresum(num);
    while(res>9)
    {
        res=squaresum(res);
    }
    if(res==1)
    {
        printf("%d is a Happy number",org);
    }
    else
    {
        printf("%d is not a Happy number",org);
    }

    return 0;
}