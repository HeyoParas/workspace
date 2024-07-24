#include<stdio.h>
#include<stdlib.h>
int* merge(int arr1[], int arr2[], int n1,int n2) {
int size=n1+n2;
int* merge;
merge=(int*)malloc(size*sizeof(int));
int i=0,j=0,k=0;
 while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merge[k] = arr1[i];
            k++,i++;
        } else {
            merge[k] = arr2[j];
            k++,j++;
        }
    }

    while (i < n1) {
        merge[k] = arr1[i];
        k++,i++;
    }

    while (j < n2) {
        merge[k] = arr2[j];
        k++,j++;
    }
for(int i=0;i<size;i++)
    {
        printf("%d ",merge[i]);
    }

return merge;
}

int main ()
{
    int arr1[]={4,5,7,8,9};
    int arr2[]={1,2,3,4,5,6,7,8,9,0};
    int n=5,m=10;
    merge(arr1,arr2,n,m);
    return 0;
}