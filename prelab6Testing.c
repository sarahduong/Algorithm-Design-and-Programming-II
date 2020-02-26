#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int ID;
    int jobType;
    float salary;
} Employee;

// Function Prototypes
Employee * readEmployeeInfo(FILE * fp, int * numElems);
Employee * getEmployeeFromID(Employee * p, int numEmps, int ID);
void setID(Employee * p, int id);
int getID(Employee * p);
void setSalary(Employee * p, float salary);
float getSalary(Employee * p);
void setjobType(Employee * p, int jobType);
int getjobType(Employee * p);
void freeStruct(Employee * p);
// END Function Prototypes

int main(void)
{
    // create file pointer and open for reading
    FILE * fPtr = fopen("Employee.txt", "r");
    if (fPtr == NULL) // check if file could be opened
    {
        printf("Error: File could not be opened. \n");
        return -1;
    }
    else
    {
        /* declare employee struct as pointer array. 
        each element contains record for diff employees */
        Employee * pEmpArray;
        int numElems = 0; // store number of elements (read from file in readEmployeeInfo func)
        pEmpArray = readEmployeeInfo(fPtr, &numElems);

        for (int i=0; i<numElems; i++)
        {
            printf("\nEmployee %d's ID: %d \n", i, pEmpArray[i].ID);
            printf("Employee Job Type Number: %d\n", pEmpArray[i].jobType);
            printf("Employee Salary = %.2f\n", pEmpArray[i].salary);
        }

        printf("\n\n***********************************************\n");
        printf("*********** TESTING FUNCTIONS BELOW ***********\n");
        printf("***********************************************\n\n");

        printf("*** testing: GET functions ***\n");
        int returnedID = getID(pEmpArray+3);
        int returnedJobType = getjobType(pEmpArray+3); // 5th employee
        float returnedSalary = getSalary(pEmpArray+3);
        printf("Employee 3 ID: %d\n", returnedID);
        printf("Employee 3 job type: %d\n", returnedJobType);
        printf("Employee 3 Salary: %.2f\n", returnedSalary);

        // test getEmployeeFromID - Employee 3333
        Employee * pPerson; // pointer to store record
        pPerson = getEmployeeFromID(pEmpArray, numElems, 3333); // gets the employee's info with ID 234324
        printf("\ngetEmployeeFromID: Salary for employee with ID %d: \n%.2f", pPerson->ID, pPerson->salary);
        printf(", and their job number is %d\n", pPerson->jobType);
            // pointer has moved when returned
        pPerson = getEmployeeFromID(pEmpArray, numElems, 5555); // gets the employee's info with ID 234324
        printf("\ngetEmployeeFromID: Salary for employee with ID %d: \n%.2f", pPerson->ID, pPerson->salary);
        printf(", and their job number is %d\n", pPerson->jobType);

        // test set employee info (set 3333 to 8888)
        printf("\n*** testing: SET, then printing GET return\n");
        setID(pEmpArray+3, 8888); 
        setSalary(pEmpArray+3, 8888.000);
        setjobType(pEmpArray+3, 888);
        // get new employee info
        returnedID = getID(pEmpArray+3);
        returnedJobType = getjobType(pEmpArray+3); // 5th employee
        returnedSalary = getSalary(pEmpArray+3);
        printf("Employee 3 ID: %d\n", returnedID);
        printf("Employee 3 job type: %d\n", returnedJobType);
        printf("Employee 3 Salary: %.2f\n", returnedSalary);

        freeStruct(pEmpArray); // frees malloced memory
    }
    fclose(fPtr);
    return 0;
}

/* this function finds how many elements are in 
   the file and stores it in numElements and returns an
   array containing employee info */
Employee *readEmployeeInfo(FILE *fp, int *numElems)
{
    fscanf(fp, "%d", numElems); // gets number of elements from file
    printf("\nNumber of Elements: %d\n", *numElems);

    // allocates memory for the struct and size int
    Employee * emp = malloc(*numElems * sizeof(Employee) + sizeof(int)); 
    if (fp == NULL)// malloc checking
    {
        printf("Memory could not be allocated\n");
        return NULL;
    }
    else
    {   
        // hide numElems behind array
        *((int *)emp-1) = *numElems; // set element -1 to size
        printf("NUMBER ELEMS AFTER SHIFTING [-1] spot: %d\n", *((int *)emp-1));

        /* read file and scan in data to store in struct
        array[i] contains all records for each employee */
        int i = 0;
        while(!feof(fp))
        {
            fscanf(fp, "%d,", &(emp[i].ID));
            fscanf(fp, "%d,", &(emp[i].jobType));
            fscanf(fp, "%f,", &(emp[i].salary));
            i++; // move to new element in array
        }
    }
    return emp; // returns array with struct info
}

/* this function retrieves employee based on their ID 
   by searching array and returns matching employee 
   to the calling function */
Employee * getEmployeeFromID(Employee * p, int numEmps, int ID)
{
    for (int i=0; i<numEmps; i++)
    {
        if (p[i].ID == ID)
        {
            return &p[i]; // returns the employee with the passed ID
        }
    }
    
    printf("\nID does not match existing employee\n");
    return NULL; // returns null if employee ID not found
}

/* this function takes in pointer to an specific employee and 
   allows user to set employee's ID to the one passed in */
void setID(Employee * p, int ID)
{
    p->ID = ID; // set passed in ID
}

/* this function returns employee ID passed into function */
int getID(Employee *p)
{
    return p->ID; // gets the ID of the employee that's passed to it
}

/* this function takes in pointer to an specific employee and 
   allows user to set employee's salary to the one passed in */
void setSalary(Employee *p, float salary)
{
    p->salary = salary;
}

/* this function returns float salary of an employee */
float getSalary(Employee *p)
{
    return p->salary;
}

/* this function takes in pointer to an specific employee and 
   allows user to set employee's jobType to the one passed in */
void setjobType(Employee *p, int jobType)
{
    p->jobType = jobType;
}

/* this function returns employee jobType passed into function */
int getjobType(Employee *p)
{
    return p->jobType;
}

/* this function frees all allocated memory */
void freeStruct(Employee * p)
{
    p = ((void *)((int *)p-1));
    free(p);
}