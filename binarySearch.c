#include <stdio.h>
#include <stdlib.h>

int binarySearch(int array[], int max, int min, int input);

int main()
{
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int lenght = sizeof(primes)/(sizeof(primes[0]));
    int n = 43;
    int index = binarySearch(primes, lenght, 0, n);
    printf("%i\n", index);
}

int binarySearch(int array[], int max, int min, int input)
{
    int mid = min + (max - min) / 2;

    if(input == array[mid])
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