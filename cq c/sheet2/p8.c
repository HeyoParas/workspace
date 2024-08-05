// chandigarh
//dnahchragi
int getlen(char s[])
{
    int len = 0, i = 0;
    while (s[i] != '\0')
    {
        len++;
        i++;
    }
    return len;
}

char *first_reverse(char s[], int start, int end)
{
    for (int i = start; i < end / 2; i++)
    {
        int temp = s[i];
        s[i] = s[end - i - 1];
        s[end - i - 1] = temp;
    }
    return s;
}
char *second_reverse(char s[], int start, int end)
{
    int n = end;
    int j = 0;
    for (int i = start; i < n; i++)
    {
        int temp = s[i];
        s[i] = s[end - 1 - j];
        s[end - 1 - j] = temp;
        j++;
        n--;
    }
    return s;
}

#include <stdio.h>
int main()
{

    char str[] = "chandigarh";
    int length = getlen(str);
    int mid = length / 2;

    if (length % 2 == 0)
    {
        first_reverse(str, 0, mid);
        second_reverse(str, mid, length);
    }
    else
    {
        first_reverse(str, 0, mid);
        second_reverse(str, mid + 1, length);
    }

    printf("%s", str);

    return 0;
}