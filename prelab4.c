#include <stdio.h>
#include <stdlib.h>

/* this function creates an array based 
   on data type size provided, sets size 
   (n = array[-1] and returns void pointer 
   to array */
void * createArray(int n, int DataTypeSize)
{
    int * arr = NULL;
    // allocate array based on data type size and size of array, + sizeof(int) as arr[-1]
    arr = malloc((n*DataTypeSize) + sizeof(int));
    if(arr == NULL) // check if arr could be malloced
    {
        printf("Memory could not be allocated\n");
    }
    else
    {
        *(arr-1) = n; // set size to arr[-1] as type "int"
    }
    return (void*)(arr); // return array as void pointer
}

// this function returns element -1 (size of array)
int getArraySize(void * array)
{
    return *((int *)array-1); // cast to int and return element
}

/* function free array and pointer to    
   array; set to NULL to avoid be 
   rereferenced in already freed memory */
void freeArray(void * arrayToFree)
{
    free(arrayToFree);
    arrayToFree = NULL;
}

int main()
{
    int n = 10; // set size

    double * array;  // create desired array type
    array = createArray(n, sizeof(double)); // pass in num elements and size

    int returnedSize = getArraySize(array); 
    printf("\nReturned size: %d\n", returnedSize);  
 
    freeArray(&array);      
}