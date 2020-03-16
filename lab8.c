#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct
{    
  int age;    
  struct studstruct *nextPtr;
} Student;

Student* createNode(int);
Student* initList();
Student* addToHead(Student*,int);
Student* addToTail(Student*,int);
void printList(Student*);
int searchAge(Student*, int);
Student* freeList(Student*);

int main()
{
  Student * head = initList();
  // create list by adding nodes
  head = addToHead(head, 1);
  head = addToHead(head, 2);
  head = addToHead(head, 3);
  head = addToHead(head, 4);
  head = addToHead(head, 5);
  
  head = addToTail(head, 6);
  head = addToTail(head, 7);
  head = addToTail(head, 8);
  head = addToTail(head, 9);
  head = addToTail(head, 10);
  
  // test searchAge
  int ageFound = searchAge(head, 8);
  printf("Location of age found: %d\n", ageFound);
  
  // print contents in linked list
  printfList(head);
  
  // free list
  freeList(head);
}

/* This function receives an integer and creates a
   Student struct with the age equal to the parameter
   passed in. It returns a pointer to the struct. */
Student * createNode(int ageToInsert)
{
    Student * newNode = (Student *)malloc(sizeof(Student));
    newNode->age = ageToInsert;
    newNode->nextPtr = NULL;
    return newNode; // return pointer to struct
}

/* function creates an empty linked list
   with NULLed data. Does not have anything 
   passed in. Returns NULL */
Student * initList()
{
    return NULL; // pass back NULL value for head (empty list)
}

/* this function allows a new node to be added
   to the beginning of the linked list. */
Student * addToHead(Student * head, int dataToInsert)
{
    Student * newHead = (Student *)malloc(sizeof(Student));
 
    if(newHead != NULL) //malloc check
    {
        newHead->age = dataToInsert;
        newHead->nextPtr = head;  
        return newHead;
    }
    else // malloc failed
    {
        printf("Memory could not be allocated.\n");
        return head;
    }
}

/* this function allows a new node to be added
   to the end of the linked list. */
Student * addToTail(Student * head, int newData)
{
    if(head == NULL)
    {
        printf("No nodes allocated - empty list. Create head node first before inserting tail.\n");
        return NULL;
    }
    else
    {
        // malloc newTail node
        Student * newTail = (Student *)malloc(sizeof(Student));
        if(newTail == NULL)
        {
            printf("Memory could not be allocated.\n");
            return newTail;
        }
        else
        {    
            // insert data to newTail node
            newTail->age = newData;
            newTail->nextPtr = NULL;
 
            Student * p = head; // create running node
            while(p->nextPtr != NULL) // move p to end of list
            {
                p = p->nextPtr;
            }
            /* found the NULL next pointer (last node), set 
            original tail next pointer to point to newTail node */
            p->nextPtr = newTail;
        
            // return updated list
            return head;
        }
    }
}

/* this function creates a moving pointer that starts
   at the head node, and prints data from the node and
   moves it up one until the list is at the end/NULL */
void printList(Student * head)
{
    if(head == NULL)
    {
        printf("List Empty. Please insert nodes before printing.\n");
    }
    else // print list
    {    
        printf("Ages in Linked List: ");
    
        Student * p; // create running pointer
    
        p = head; // set p to beginning of list 
        while(p != NULL) // loop when not at end of list
        {
            printf("%d  ", p->age); // print data
            p = p->nextPtr; // move to next mode
        }
        printf("\n");
    }
}

/* this function searches the list for the matching age 
   passed in. It returns the location of the first struct 
   with the matching age, or -1 if there is no match. */
int searchAge(Student * head, int ageToMatch)
{
    Student * p = head; // set running pointer to beginning of list
    int structLoc = 0; // location of struct in list
    while(p != NULL) // loop while list has not ended
    {
        printf("Struct Location: %d", structLoc);
        printf(", Current age in struct: %d\n", p->age);
        if(ageToMatch == p->age)
        {
            return structLoc; // return position of matching struct           
        }
        else
        {
            p = p->nextPtr; // move up one
        }
        structLoc++;
    }
    return -1; // no struct with matching age found, return -1
}




/* this function creates a holding pointer that is set to 
   the address of the head node and frees it. It moves the 
   pointer up one until it reaches the end of the list (NULL).
   It returns the head of the linked list */
Student * freeList(Student * head)
{
    Student * p = head; // set running pointer to start at head
 
    while(p != NULL) // loop while list has not ended
    {
        head = p; // set head to running ptr
        p = p->nextPtr; // move up one
        free(head); // free head
    }
    head = NULL;
    return head; // head set to NULL
}
