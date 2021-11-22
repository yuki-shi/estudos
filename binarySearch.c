#include <stdio.h>
#include <stdlib.h>

int binarySearch(int array[], int max, int min, int input);

const PRIMES[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main(int argc, char*argv[])
{
    if(argc != 2)
    {
        printf("Uso: ./binarySearch elemento desejado\n");
        return 1;
    }
    int lenght = sizeof(PRIMES)/(sizeof(PRIMES[0]));
    int index = binarySearch(PRIMES, lenght, 0, atoi(argv[1]));
    printf("Index: %i\n", index);
    return 0;
}

int binarySearch(int array[], int max, int min, int input)
{
    int mid = min + (max - min) / 2;
    
    if(min > max)
    {
        printf("Erro!\n");
        exit(1);
    }
    else if(input == array[mid])
    {
        return mid;
    }
    else if(input > array[mid])
    {
        return binarySearch(array, max, mid + 1, input);
    }
    else
    {
        return binarySearch(array, mid - 1, min, input);
    }
}