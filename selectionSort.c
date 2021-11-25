#include<stdio.h>

void selectionSort(int array[], int n);
void swap(int*x, int*y);
void printArray(int array[], int n);

int main()
{
    int arr[] = {1, 64, 25, 12, 22, 11, 23};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, size);
    printArray(arr, size);
    return 0;
}

void selectionSort(int array[], int n)
{
    int min = 0;

    for(int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if(array[j] < array[min])
            {
                min = j;
            }
        }
        swap(&array[i], &array[min]);
    }
}

void swap(int*x, int*y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void printArray(int array[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}