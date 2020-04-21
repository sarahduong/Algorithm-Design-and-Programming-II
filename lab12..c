#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{
    int age;
    float priority;
    struct studstruct *previousPtr, *nextPtr;
}Student;

typedef struct linkedlist{
    Student *head, *tail;
    int numOfItems;
}StudentList;

typedef struct queuelist{
    StudentList* list;
}PQueue;

PQueue initPQueue();
Student* createNode(float,int);
int insertPQ(float,int,PQueue);
Student* deleteMin(PQueue);
Student* deleteMax(PQueue);
Student* returnMin(PQueue); // returns but does not delete
Student* returnMax(PQueue); // returns but does not delete
void freePQueue(PQueue); // Free all malloced space
void printPQueue(PQueue);

int main()
{
    PQueue list = initPQueue();

    insertPQ(3, 30, list);
    insertPQ(8, 80, list);
    insertPQ(4, 40, list);
    insertPQ(1, 10, list);
    insertPQ(2, 20, list);
    insertPQ(9, 90, list);
    insertPQ(7, 70, list);
    insertPQ(10, 100, list);
    insertPQ(6, 60, list);
    insertPQ(5, 50, list);

    printf("Original List:     ");   
    printPQueue(list);

    deleteMax(list);
    printf("\nDeleteMax list:    ");
    printPQueue(list);

    deleteMax(list);
    printf("\nDeleteMax list:    ");
    printPQueue(list);

    deleteMax(list);
    printf("\nDeleteMax list:    ");
    printPQueue(list);

    deleteMin(list);
    printf("\nDeleteMin list:    ");
    printPQueue(list);

    deleteMin(list);
    printf("\nDeleteMin list:    ");
    printPQueue(list);

    deleteMin(list);
    printf("\nDeleteMin list:    ");
    printPQueue(list);
    
    Student * min = returnMin(list);
    printf("\nMinimum Returned: %.1f", min->priority);
    Student * max = returnMax(list);
    printf("\nMaximum Returned: %.1f", max->priority);

    createNode(700, 51);
    freePQueue(list);
}


/* this function initializes
   an empty priority queue */
PQueue initPQueue()
{
    PQueue newQ; // create new queue
    newQ.list = malloc(sizeof(StudentList)); // malloc queue pointer
    newQ.list->head = newQ.list->tail; // set head node equal to tail

    newQ.list->head = NULL; // set head to NULL
    newQ.list->tail = NULL; // set tail to NULL
    newQ.list->numOfItems = 0; // initialize size to 0

    return newQ;
}

/* this function creates a new node with priority and data 
   passed in, and passes it back to the calling function */
Student * createNode(float priority, int dataToInsert)
{
    Student * newNode = malloc(sizeof(Student));
    if(newNode == NULL) // malloc checking
    {
        printf("Memory could not be allocated.\n");
        return NULL;
    }
    else
    {  
        newNode->priority = priority;
        newNode->age = dataToInsert;
        newNode->nextPtr = NULL;   
        return newNode;
    }
}

/* this function inserts floats into
   the priority queue, which it receives
   with the queue. no return value */
int insertPQ(float priority, int dataToInsert, PQueue queue)
{
    Student * newNode = malloc(sizeof(Student));
    if(newNode == NULL) // malloc checking
    {
        printf("Memory could not be allocated.\n");
        return -1;
    }
    else
    {
        // set newNode variables
        newNode->priority = priority;
        newNode->age = dataToInsert;
        newNode->nextPtr = NULL;

        if(queue.list->head != NULL) // list has contents
        {
            Student * p = queue.list->head;  // create temp node and set to beginning of list
            if(newNode->priority > p->priority) // new node greater than head, set new head
            {
                newNode->nextPtr = queue.list->head; // new node point to current head
                queue.list->head = newNode; // set new node to head
            }
            else
            {
                while(p->nextPtr != NULL && newNode->priority < p->nextPtr->priority) // when p not at end of list and newNode less than p
                {
                    p = p->nextPtr; // move up the list
                }
                    // Cases after first node
                    if(p->nextPtr != NULL) // set when not at last node (middle of list)
                    {                  
                        // set next of newnode to next of previous node
                        newNode->nextPtr = p->nextPtr;
                            
                        // set next of previous node to newnode
                        p->nextPtr = newNode;
                            
                        // set previous pointer of newnode to the previous node
                        newNode->previousPtr = p;
                            
                            // set previous pointer of newNode->next to newNode
                            if (newNode->nextPtr != NULL)
                            {
                                newNode->nextPtr->previousPtr = newNode;
                            }
                    }
                    else // set at last node, tail & info
                    {
                        queue.list->tail->nextPtr = newNode;
                        newNode->previousPtr = queue.list->tail;
                        queue.list->tail = newNode;
                    }  
            }
        }
        else // set head and tail for first node in list
        {
            queue.list->head = newNode;
            queue.list->tail = newNode;
        }
        return 1;
    }
}

/* this function receives the queue
   and deletes the minimum priority value */
Student * deleteMin(PQueue queue)
{
    Student * p = queue.list->tail; // set p to tail
    if(p == NULL)
    {
        printf("List is empty. No nodes can be deleted\n");
        return p;
    }
    else
    {
        if(p->nextPtr != NULL)
        {
            p->nextPtr->previousPtr = p->previousPtr;
        }
        if(p->previousPtr != NULL)
        {
            p->previousPtr->nextPtr = p->nextPtr;
            queue.list->tail = p->previousPtr;
            queue.list->tail->nextPtr = NULL;
    	}
        queue.list->numOfItems--; // decrease size of queue
        return (void *)p;
    }
}

/* this function receives the queue
   and deletes the maximum value */
Student * deleteMax(PQueue queue)
{
    Student * p = queue.list->head;  // set node to beginning of list
    if(p == NULL)
    {
        printf("List is empty. No nodes can be deleted\n");
        return NULL;
    }
    else
    {
        queue.list->head = p->nextPtr; // move head up one
        queue.list->numOfItems--; // decrease size of queue
    }
    return p;
}

/* this function returns the
   minimum value in the queue */
Student * returnMin(PQueue queue)
{
    Student * p = queue.list->tail;
    return p;
}

/* this function returns the
   maximum value in the queue */
Student * returnMax(PQueue queue)
{
    Student * p = queue.list->head;
    if(p == NULL)
    {
        printf("No maximum value. List is empty.\n");
        return NULL;
    }
    else
    {
        return p;
    }
}

/* this function prints priority and 
   data values from the queue receieved */
void printPQueue(PQueue queue)
{
    Student * p;
    p = queue.list->head;  // set running node to beginning of list

    if(p == NULL) // no head node set
    {
        printf("List is empty. Please add a node before printing.");
    }
    else // list is not empty
    {
        while (p != NULL)
        {
            printf(" %.2f (%d) --> ", p->priority, p->age);
            p = p->nextPtr;
        }
        printf("End\n");
    }
}

/* this function receives the queue
   and frees all allocated memory */
void freePQueue(PQueue queue)
{
    Student * p;
    p = queue.list->head;  // set running node to beginning of list
    if(p == NULL)
    {
        printf("No nodes to free. List is empty.\n");
    }
    else
    {
        while(p != NULL)
        {
            queue.list->head = p->nextPtr;
            free(p); // free p
            p = queue.list->head;
        }
        free(queue.list); // free head
    }
}
