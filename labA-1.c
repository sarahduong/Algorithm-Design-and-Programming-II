#include <stdio.h>
#include <stdlib.h>

int addition(int arr[], int size)
{
	int sum = 0;
	int i = 0;
	for (i = 0; i < size; i++)
	{

		sum = sum + arr[i]; // add number to sum
	}
	return sum; // return sum to main function
}


int main()
{
	int size = 5;
	int array[5] = {5,10,8,2,13};

	int ReturnedSum = addition(array, size); // call addition function and store returned value

	// Print Output
	printf("Array is: %d, %d, %d, %d, %d \n", array[0], array[1], array[2], array[3], array[4]);
	printf("Sum is %d\n\n", ReturnedSum);

	return 0;
}