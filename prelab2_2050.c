#include <stdio.h>
#include <stdlib.h>

void numbers(int array[], int size, int testInt, int *lessThan, int *greatThan)
{
    int i;
    *lessThan = *greatThan = 0; // initialize to 0

    for(i=0; i<size; i++)
    {
        if(array[i] < testInt)
        {
            *lessThan = *lessThan + 1; // add one to less than count and store
        }
        if(array[i] > testInt)
        {
            *greatThan = *greatThan + 1; // add one to greater than count and store
        }
    }
}

int main()
{
    int size = 10; // initialize and define size variable
    int a[10] = {3,15,7,35,36,27,5,24,43,9}; // intialize array

    int testNum = 20;
    printf("\nNumber to test: %d\n", testNum);

    int less = 0;
    int great = 0;
    numbers(a, size, testNum, &less, &great);

    printf("Numbers less than test: %d\n", less);
    printf("Numbers greater than test: %d\n\n", great);

}