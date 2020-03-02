#include <stdio.h>
#include <stdlib.h>

// create struct with 4 variables
typedef struct 
{
    float salary;
    int age;
    int empID;
    int ssn;
} Record;


// Function Prototypes
Record * readRecordFile(FILE *);
int getSize(Record *);
Record * getEmpByAge(Record *, int);
void adjustSalaries(Record *, int, float);
void freeRecordArray(Record *);


/* the main function creates a file pointer and 
   opens a file of employee records for reading.
   It calls readRecordFile to read information, 
   as well as calling a freeRecordArray to free memory
   and close the file */
int main(void)
{
    // create file pointer and open for reading
    FILE * fPtr = fopen("employee.csv", "r");
    if (fPtr == NULL) // check if file could be opened
    {
        printf("Error: File could not be opened. \n");
        return -1;
    }
    else
    {
        // declare employee struct as pointer array. each element contains record for diff employees 
        Record * pEmpArray;
        pEmpArray = readRecordFile(fPtr);
        
        // TEST FUNCTIONS
        /*
        int numRec = getSize(pEmpArray);
        printf("size: %d", numRec);
        
        
        for (int i=0; i<5; i++)
        {
            printf("\nEmployee %d's Salary: %.2f \n", i, pEmpArray[i].salary);
            printf("Employee Age: %d\n", pEmpArray[i].age);
            printf("Employee ID = %d\n", pEmpArray[i].empID);
            printf("Employee SSN = %d\n", pEmpArray[i].ssn);
        } 

        
        Record * person;
        person = getEmpByAge(pEmpArray, 20);
        printf("getEmpByAge: Salary for employee with age %d: \n%.2f", person->age, person->salary);
        printf(", EmpID is %d, and SSN is %d\n", person->empID, person ->ssn);
        
        adjustSalaries(pEmpArray, 18, 2.00);

        
        for (int i=0; i<5; i++)
        {
            printf("\nEmployee %d's Adjusted Salary: %.2f \n", i, pEmpArray[i].salary);
        }
        */

       freeRecordArray(pEmpArray); // frees malloced memory
    }
    fclose(fPtr);
    return 0;
}



/* this function receives a file pointer and gets size of
   array and hides it as an integer behind the struct array
   It populates the array w/ employee info and returns array */
Record * readRecordFile(FILE * fPtr)
{
    int numRecords = 0; // variable to hold number of total records
    fscanf(fPtr, "%d", &numRecords); // gets number of elements from file

    // allocates memory for the struct and numRecords integer
    Record * emp = malloc(numRecords * sizeof(Record) + sizeof(int)); 
    if (fPtr == NULL)// malloc checking
    {
        printf("Memory could not be allocated\n");
        return NULL;
    }
    else
    {   
        *((int *)emp-1) = numRecords; // set element -1 to numRecord
 
        // read file and scan in data to store in struct
        // array[i] contains all records for each employee 
        int i = 0;
        while(!feof(fPtr))
        {
            fscanf(fPtr, "%f,", &(emp[i].salary));
            fscanf(fPtr, "%d,", &(emp[i].age));
            fscanf(fPtr, "%d,", &(emp[i].empID));
            fscanf(fPtr, "%d,", &(emp[i].ssn));           
            i++; // move to new element in array
        }
    }
    return emp; // returns array with struct info
}

/* this function receieves the array of structs and 
   retrieves the size of the record from element -1 
   of array. It returns the size as an integer */
int getSize(Record * emp)
{
    return *((int *)emp-1);
}    



/* this fumction searches the array for matching age and
   returns the first matching employee info */
Record * getEmpByAge(Record * emp, int age)
{
    int numRecords = getSize(emp);
    for (int i=0; i < numRecords; i++)
    {
        if (emp[i].age == age)
        {
            return &emp[i]; // returns the employee with the passed ID
        }
    } 

    printf("\nAge does not match existing employee record.\n");
    return NULL; // returns null if employee ID not found

}


/* this function takes in the array of stucts, age of employee 
   with salary to adjust, and number of multiply the salary by.
   It multiples the salary by the float number passed in and
   saves it as the new salary */
void adjustSalaries(Record * emp, int age, float multiSalary)
{
    int numRecords = getSize(emp);
    for (int i=0; i< numRecords; i++)
    {
        if (emp[i].age == age)
        {
            emp[i].salary = ((emp[i].salary) * (multiSalary));
        }
    }
}

/* this function receieves the array and frees all memory 
   previously malloced */
void freeRecordArray(Record * empArray)
{
    empArray = ((void *)((int *)empArray-1));
    free(empArray);
} 
