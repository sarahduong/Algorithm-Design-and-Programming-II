#include <stdio.h>
#include <stdlib.h>

/* this function creates a table using arrays of arrays
   by using row and column parameters and hiding row
   behind pointers and column in element -1. it takes in 3 integers
   and returns a void double pointer to the array */
void ** create2DArray(int rows, int columns, int elementSize)
{
    float ** array; // create float double pointer from void double pointer
 
    // allocate memory for pointer to rows and cast memory to double float pointer
    array = (float **)malloc(sizeof(void *) * rows + sizeof(float)); 
    if(array == NULL)
    {
        printf("Memory could not be allocated.\n");
    }
    else
    { 
        *((float *)array) = rows; // store row number before array of pointers
        (float *)array++; // move pointer up one

        // malloc columns based on length/size
        for(int i=0; i<rows; i++)
        {
            *(array+i) = (float *)malloc(columns * elementSize + sizeof(float));
            if(*(array+i) == NULL)
            {
                printf("Memory could not be allocated.\n");
                break;
            }
       }

        // store number of columns before each row
        for (int r=0; r<rows; r++)
        {
            array[r][-1] = columns;
        } 
        
    }
    return (void **)array; // return void pointer to array
}

/* this function takes in a doulble pointer and 
   returns row size as integer from behind row of pointers */
int getRowSize(void ** array)
{
    int rowSize = *((float *)array-1);
 
    return rowSize;
}

/* this function takes in a double pointer and
   returns column size as integer from element array[-1] */

int getColSize(void ** array, int rowNo)
{
    float rowsPresent = getRowSize((void **)array);
    if(rowNo <= rowsPresent) // check if rowNo exists
    {
        float colSize = *(*( (float **)array + rowNo)-1);
        return colSize;
    }
    else
    {
        return -1;
    }
}

/* this function prints out values in array in each row
   and number of columns in each row */
void printTable(void ** array)
{
    float rowSize = getRowSize((void **)array); // get row size for counter
    float colSize = getColSize((void **)array, rowSize); // get column size for counter

    printf("\nNumber of total rows: %f\n", rowSize);

    for (int i=0; i<rowSize; i++)
    {
        printf("\nIn row %d: \n", i);
        printf("Number of Columns: %f\n", colSize);
        for(int j=0; j<colSize; j++)
        {
            printf("Array[%d][%d] = %d\n", i, j, *(((int *)array+i)+j));
        } 
    }
}

/* this function takes in a pointer to an array
   and frees the contents within each row and
   pointers to the arrays */
void freeTable(void ** array)
{
    float rowSize = getRowSize((void**)array); // get row size to free numer of rows allocated
    *array = (void **)((float *)(array-1)); // move array back one float (holds column size)
 
    for(int i=0; i<rowSize; i++)
    {
        free(array+i); // free all rows
    }
    free(array); // free array of pointers to rows
}

/* the main creates an array of a given data type,
   calls and create table to malloc an array of
   arrays, populates the array, calls function to 
   print the table and frees allocated memory */
int main()
{
    float ** array; // set data type of array to float
    // initialize size of rows and columns
    int rowSize = 5;
    int colSize = 5;
 
    // get table of array
    array = (float **)create2DArray(rowSize, colSize, sizeof(void *));

    // initialize array values to 0
    for (int i=0; i<rowSize; i++)
    {
        for(int j=0; j<colSize; j++)
        {
            *(((int *)array+i)+j) = 0;
        } 
    }
    printTable((void**)array);

    freeTable((void **)array);
}