#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array1, *array2 , n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    array1 = (int *)malloc(n * sizeof(int));
    if (array1 == NULL) {
        printf("Memory not allocated");
        return 1; 
    }
    array2 = (int *)malloc(n * sizeof(int));
    if (array2 == NULL) {
        printf("Memory not allocated");
        return 1; 
    }
    printf("Enter elements of the first array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array1[i]);
    }
    for (int i = 0; i < n; i++) {
        array2[i] = array1[i];
    }
    printf("Elements of the first array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array1[i]);
    }
    printf("\n");
    printf("Elements of the second array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");
    free(array1);
    free(array2);
    return 0;
}
