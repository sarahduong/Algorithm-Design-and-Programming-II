#include <stdio.h>
#include <stdlib.h>

typedef struct weatherStruct
{
    float data;
}Weather;


Weather ** readRecord(FILE * fPtr)
{
    // allocates memory for the struct and numRecords integer
    Weather ** arr = malloc(sizeof(Weather *));

    if (fPtr == NULL)// malloc checking
    {
        printf("Memory could not be allocated\n");
        return NULL;
    }
    else
    {
    	int i = 0;
        while(!feof(fPtr))
        {
            *(arr+i) = (Weather *)malloc(sizeof(Weather));

            fscanf(fPtr, "%f,", &(arr[i]->data));
            printf("%.2f\n", arr[i]->data);
        }
    }
    return (Weather **)arr; // returns array with struct info
}

int compare(void * dataA, void * dataB)
{
    Weather * a = dataA;
    Weather * b = dataB;

    if(a->data > b->data) // if first is larger
    {
        return 1;
    }
    if(a->data < b->data) // if second is larger
    {
        return -1;
    }

    return 0; // if data is equal
}

int binarySearch(void ** orderedArray, int first, int last, void * searchQuery)
{
    if(first > last)
        return -1; // no element found

    int mid =  ((first + last)/2);
    Weather * midStruct = malloc(sizeof(Weather));
    midStruct->data = mid;
    printf("searchQuery: %d\n", (int)searchQuery);
    int compareReturn = compare(searchQuery, &(midStruct->data));
    free(midStruct);
    
    if(compareReturn == 0) // matched number in array
    {
        return mid;
    }
    else // no match yet, call function to compare
    {
        if(compareReturn < 0)
            return binarySearch(orderedArray, first, mid-1, searchQuery);

        if(compareReturn > 0)
            return binarySearch(orderedArray, mid+1, last, searchQuery);
    }
    return -1; 
}

int main(void)
{
    printf("hello\n");
    FILE * fPtr  = fopen("weather.csv", "r");

    if(fPtr)
    {
        Weather ** orderedArray = readRecord(fPtr); // create array of structs
        fclose(fPtr);
        if(orderedArray)
        {
                float target = 12;
                ///printf("Number to search: ");
                ///scanf("%f", &target);
                int searchReturn = binarySearch((void **)orderedArray, 0, 52, &target);
            if (searchReturn == -1)
            {
                printf("Element could not be found in array.\n");
            }
            else
            {
                printf("Element located at index %d.\n", searchReturn);
            }
        }
    }
}
