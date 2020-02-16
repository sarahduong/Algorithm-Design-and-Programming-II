#include <stdio.h>
#include <stdlib.h>

void countGrades(int arr[], int size, int BBoundary, int CBoundary, int* NoOfAs, int* NoOfBs, int* NoOfCs)
{
    int i = 0;
    for(i=0; i<size; i++) // loop through array
    {
        // A Count Condition
        if(arr[i]>=BBoundary)
        {
            *NoOfAs = (*NoOfAs + 1); // add one to A count
        }
        // B Count Condition
        if(arr[i]>=CBoundary && arr[i]<BBoundary)
        {
            *NoOfBs = (*NoOfBs + 1); // add one to B count
        }
        // C Count Condition
        if(arr[i]<CBoundary)
        {
            *NoOfCs = (*NoOfCs + 1); // add one to C count
        }
    } // end for
}

int main()
{
    int array[30] = {57,99,53,58,46,46,92,72,43,82,42,90,70,65,88,53,59,75,43,45,66,69,63,93,77,98,99,40,88,49};
    int size = sizeof(array)/sizeof(array[0]);
    int BBoundary = 80, CBoundary = 60;

    // define variables to store count to pass into function
    int Acount = 0;
    int Bcount = 0;
    int Ccount = 0;

    // call countGrades function
    countGrades(array, size, BBoundary, CBoundary, &Acount, &Bcount, &Ccount);
    
    printf("\n");
    printf("%d students got A,", Acount); // print A count
    printf(" %d students got B,", Bcount); // print B count
    printf(" and %d students got C.\n\n", Ccount); // print C count
    return 0;
}
