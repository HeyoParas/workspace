#include <stdio.h>
#define MAX 100 
void countFrequency(int arr[], int size) {
    int hash[MAX] = {0};
    for (int i = 0; i < size; i++)
    {
        hash[arr[i]]++;
    }
    printf("Frequency of each element:\n");
    for (int i = 0; i < MAX; i++) 
    {
        if (hash[i] > 0)
        {
            printf("%d occurs %d times\n", i, hash[i]);
        }
    }
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    if (size <= 0) 
    {
        printf("Invalid array size\n");
        return 1;
    }
    int arr[size];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) 
    {
        scanf("%d", &arr[i]);
    }
    countFrequency(arr, size);
    return 0;
}
