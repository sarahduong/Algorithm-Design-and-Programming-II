#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* this function gets size array from file, reading 
   float values to store and return to calling
   main function */
float * readFloatFileIntoArray(FILE *fPtr, int * length)
{
    // read first integer to find size of array
    fscanf(fPtr, "%d", length); // scan and save integer to memory address of *length

    float * array; // create array to hold floats (pointer)
    array = malloc(*length * sizeof(float)); // allocate memory for floats + int

// "hide" size of array value
// *(array-1) = *length; // *length converted from decimal to float because of array input
/*
printf("*length value: %d\n", *length);
printf("*(array-1) value: %f\n", *(array-1));
*/

    // set array start at second value
    *array = *(array+1); // start array at float values

    int i;        
    // for loop stores float values from file into array
    for(i=0; i<*length; i++)
    {
        fscanf(fPtr, "%f", (array+i));
    }
    return array;
}

/* function free array and pointer to
   array; set to NULL to avoid be 
   rereferenced in already freed memory */
void freeArray(float ** arrayToFree)
{
    free(*arrayToFree);
    *arrayToFree = NULL;
}

int main()
{
    FILE * fPtr;
    fPtr = fopen("TestFile.txt", "r");
    if(fPtr == NULL)
    {
        printf("\nError: File cannot be opened.\n");
    }
    else
    { 
        int arraySize;
        // Call function to get array
        float * returnedArray = readFloatFileIntoArray(fPtr, &arraySize); // pass file pointer and size of array
        
        printf("\nNumber of elements in array: %d\n", arraySize);
        int i;
        for(i=0; i<arraySize; i++)
        {
            printf("Number in array[%d]: %.3f\n", i, *(returnedArray+i));   
        }
        freeArray(&returnedArray);
    }
}