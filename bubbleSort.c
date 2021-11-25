#include<stdio.h>

void bubbleSort(int array[], int n);
void swap(int*x, int*y);
void printArray(int array[], int n);

int main()
{
    int arr[] = {64, 25, 12, 22, 11, 23};
    int size = sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}

void bubbleSort(int array[], int n)
{
    int cont = 0;
    while(cont != n-1)
    {
        for (int i = 0; i < n-1-cont; i++)
        {
            if(array[i] > array[i+1])
            {
                swap(&array[i], &array[i+1]);
            }
        }  
        cont++;
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