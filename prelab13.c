#include <stdio.h>
#include <stdlib.c>

int compare(void * c, void * d)
{
    int * a; 
    int * b;
    a = c;
    b = d;

    if(*a > *b)
    {
        return 1;
    }
    if(*a < *b)
    {
        return -1;
    }

    return 0; // number found

}

int binarySearch(int orderedArray[], int first, int last, int query)
{
    if(first > last)
        return -1; // no element found

    int mid =  ((first + last)/2);    
    int compareReturn = compare(&query, &orderedArray[mid]);

    if(compareReturn == 0) // matched number in array
    {
        return mid;
    }
    else // no match yet, call function to compare
    {
        if(compareReturn < 0)
            return binarySearch(orderedArray, first, mid-1, query);

        if(compareReturn > 0)
            return binarySearch(orderedArray, mid+1, last, query);
    }
    return -1; // no element found
}

int main(void)
{
    int array[] = {2,4,6,8,10,12,14,16,18,20};
    int findNum = 22;
    int sizeOfArray = 10;

    int first = 0;
    int last = sizeOfArray;
    int searchReturn = binarySearch(array, first, last, findNum);

    if (searchReturn == -1)
    {
        printf("Element could not be found in array.\n");
    }
    else
    {
        printf("Element located at index %d.\n", searchReturn);
    }
}
