#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* function free array and pointer to    
   array; set to NULL to avoid be 
   rereferenced in already freed memory */
void freeIntArray(int ** arrPtr)
{
    free(*arrPtr);
    *arrPtr = NULL;
}

/* this function reads number of employees and creates an array based on size, 
   reading data from file into the array and returning it the the calling function
   It also calculates the average age of all employees.
*/ 
int * readIntAgeIntoArray(FILE* fp, int* totalNumOfEmployee, float* averageAge)
{
    // get size of array
    fscanf(fp, "%d", totalNumOfEmployee); // scan and save integer to memory address of *length
    // printf("Num Employees: %d\n\n", *totalNumOfEmployee);
 
    int * array; // create array to hold floats (pointer)
    array = malloc(*totalNumOfEmployee * sizeof(int)); // allocate memory for array
    if(array == NULL)
    {
       printf("Memory allocation failed.");
    }
    else
    {
      *array = *(array+1); // start array at second value in file

      int i;        
      // for loop stores float values from file into array
      for(i=0; i<*totalNumOfEmployee; i++)
      {
         fscanf(fp, "%d", (array+i));
      }

      // Calculate average
      i=0;
      float addedAge = 0; // create variable to store running total calculation
      for(i=0; i<*totalNumOfEmployee; i++)
      {
           addedAge = addedAge + *(array+i); // running total
      }

         *averageAge = (float)(addedAge) / (*totalNumOfEmployee); // calculate average, store into *averageAge
    }
    return array; // return values in array
}

/* this function finds largest and smallest value in array
   and stores it as a pointer in minAge and maxAge */
void findMinMax(int * arr, int size, int * minAge, int * maxAge)
{
    *minAge = *(arr);
    *maxAge = *(arr);

    // loop through and compare array data 
    int i = 0;
    for(i=0; i<size; i++)
    {
        if(*(arr+i) > *maxAge)
        {
            *maxAge = *(arr+i); // replace *maxAge if *(arr+1) is larger
        }
        if(*(arr+i) < *minAge)
        {
            *minAge = *(arr+i); // replace *minAge if *(arr+1) is smaller
        }
    } // end for
}

int main()
{
    FILE * fPtr; // create file pointer
    fPtr = fopen("employeeAge.txt", "r"); // open file

    // check if file can be opened
    if(fPtr == NULL)
    {
        printf("\nError: File cannot be opened.\n");
    }
    else
    { 
        int numEmployees; // variable to store number of employees
        float averageAge; // variable to store average age
        int * returnedArray = readIntAgeIntoArray(fPtr, &numEmployees, &averageAge); // get data from array and return to main
        printf("\nThere are a total of %d employees, the average age of them is %.2f\n", numEmployees, averageAge); // print number of employees and average age

        int minAge; // variable to score minimum age
        int maxAge; // variable to store maximum age
        findMinMax(returnedArray, numEmployees, &minAge, &maxAge); // call function to find min and max age
        printf("Largest age is %d, smallest age is %d\n", maxAge, minAge); // print maxAge and minAge
        freeIntArray(&returnedArray); // call function to free malloced memory
    }
    fclose(fp);
    return 0;
}
