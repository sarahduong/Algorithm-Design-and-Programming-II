#include <stdio.h>
#include <stdlib.h>

/* this function creates a table using arrays of arrays
   by using row and column parameters and hiding size
   in element a[-2] and a[-1]. returns void pointer to array */
void ** createTable(int rows, int columns, int elementSize)
{
    float ** array; // create float array

    // allocate memory for pointer to rows and cast memory to double float pointer
    array = (float**)malloc(sizeof(void *) * rows); 
    if(array == NULL)
    {
        printf("Memory could not be allocated.\n");
    }
    else
    { 
        *((int *)array-2) = rows;
        *((int *)array-1) = columns;

        // malloc columns based on length/size
        for(int i=0; i<rows; i++)
        {
            *(array+i) = malloc(columns * elementSize);
                if(*(array+i) == NULL)
                {
                    printf("Memory could not be allocated.\n");
                    break;
                }
       }
    }
    return (void **)array; // return void pointer to array
}

/* this function returns row size as integer
   from element a[-2] */
int getRowSize(void ** array)
{
    int rowSize = *((int *)array-2);

    return rowSize;
}

/* this function returns column size as integer
   from element a[-1] */
int getColSize(void ** array)
{
    int colSize = *((int *)array-1);

    return colSize;
}

/* this function takes in a pointer to an array
   and frees the contents within each row and
   pointers to the arrays */
void freeTable(void ** array)
{
    int rowSize = getRowSize((void**)array); // get row size to free all rows
    *array = (void **)((int *)(array-2)); // move array back two integers

    for(int i=0; i<rowSize; i++)
    {
        free(array+i); // free all rows
    }
    free(array); // free array of pointers to rows
}

int main()
{
    float ** array; // set data type of array to float
    // initialize size of rows and columns
    int rowSize = 4;
    int colSize = 3;

    // get table of array
    array = (float **)createTable(rowSize, colSize, sizeof(float));

    // set array elements to 0
    int count=0;
    for (int i=0; i<rowSize; i++)
    {
        for(int j=0; j<colSize; j++)
        {
            count++;
            array[i][j] = count;
        }
    }

    // call getRowSize and print return
    int row = getRowSize((void **)array);
    printf("/n/nNumber of Rows: %d\n", row);

    // call getColSize and print return
    int col = getColSize((void **)array);
    printf("Number of Columns: %d\n\n\n", col);


    // TEST: print elements and rows/columns
    for (int i=0; i<rowSize; i++)
    {
        printf("\nNumber of Rows(%d): %d\n", i, *( (int *)array -2));
        printf("Number of Columns: %d\n", *( (int *)array-1)); 
        for(int j=0; j<colSize; j++)
        {
            printf("array[%d][%d] = %f\n", i, j, array[i][j]);
        }
    }
    freeTable((void **)array);
}