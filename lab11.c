#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{
    int age;
    struct studstruct *nextPtr;
} Student;

typedef struct linkedlist{
    Student *head, *tail;
    int numOfItems;
    int numOfOdd;
    int numOfEven;
} StudentList;

typedef struct queuelist{
    StudentList* list;
} Queue;


Queue initQueue();
int enQueue(int, Queue);
Student* deQueue(Queue);
int getQsize(Queue);
int getNumOfEven(Queue);
void printQueue(Queue);
void emptyQueue(Queue);

int main()
{
    Queue list = initQueue();
    enQueue(1, list);
    enQueue(2, list);
    enQueue(3, list);
    enQueue(4, list);
    enQueue(5, list);
    enQueue(6, list);
    enQueue(7, list);
    enQueue(8, list);

    printf("Nodes enqueued: ");
    printQueue(list);
    int size = getQsize(list);
    int even = getNumOfEven(list);
    printf("\nSize of queue = %d\nNumOfEvens = %d\n", size, even);
    
    deQueue(list);
    printf("\nNode dequeued: ");
    printQueue(list);
    size = getQsize(list);
    even = getNumOfEven(list);
    printf("\nSize of queue = %d\nNumOfEvens = %d\n", size, even);
    
    deQueue(list);
    printf("\nNode dequeued: ");
    printQueue(list);
    size = getQsize(list);
    even = getNumOfEven(list);
    printf("\nSize of queue = %d\nNumOfEvens = %d\n", size, even);

    deQueue(list);
    printf("\nNode dequeued: ");
    printQueue(list);
    size = getQsize(list);
    even = getNumOfEven(list);
    printf("\nSize of queue = %d\nNumOfEvens = %d\n", size, even);
    
    emptyQueue(list);
    printf("\nGot to end of program!");
}

/* this function creates a queue and
   returns an empty queue */
Queue initQueue()
{
    Queue newQ; // create new queue
    newQ.list = malloc(sizeof(StudentList)); // malloc queue pointer
    newQ.list->numOfItems = 0; // set size of queue to 0 (empty)
    newQ.list->head = newQ.list->tail; // set head node equal to tail

    newQ.list->head = NULL; // set head to NULL
    newQ.list->tail = NULL; // set tail to NULL
    // initialize queue variables
    newQ.list->numOfItems = 0;
    newQ.list->numOfOdd = 0;
    newQ.list->numOfEven = 0; 
    return newQ;
}

// and returns an int error code
int enQueue(int dataToInsert, Queue queue)
{
    Student * newNode = malloc(sizeof(Student)); // malloc new node for enqueue
    if(newNode == NULL)
    {
        printf("Memory could not be allocated\n");
        return 1;
    }
    else
    {
        // check if data is odd or even value
        if(dataToInsert % 2 == 0)
        {
            queue.list->numOfEven++; // increase even
        }
        else
        {
            queue.list->numOfOdd++; // increase odd
        }

        newNode->age = dataToInsert; // set data for newNode (equal to size in this case)
        newNode->nextPtr = NULL; // set next pointer to NULL

        if(queue.list->tail == NULL) // if tail is NULL (empty list)
        {
            // set head and tail node equal to new node
            queue.list->head = newNode;
            queue.list->tail = newNode;
            // increase size of queue by one
            queue.list->numOfItems++;
        }
        else // if list is not empty
        {
            queue.list->tail->nextPtr = newNode; // move tail ptr up one, set to newNode
            queue.list->tail = newNode; // set new tail to newNode/newtail
            queue.list->numOfItems++; // increase size of queue      
        }
        return 0; // successful enqueue
    }
}

Student * deQueue(Queue queue)
{
    Student * p = queue.list->head;  // set node to beginning of list

    // check if data is odd or even value
    if(p->age % 2 == 0)
    {
        queue.list->numOfEven--; // decrease even
    }
    else
    {
        queue.list->numOfOdd--; // decrease odd
    }

    queue.list->head = p->nextPtr; // move head up one
    queue.list->numOfItems--; // decrease size of queue
    return p;
}

int getQsize(Queue queue)
{
    int qSize = queue.list->numOfItems; // access size member of struct
    return qSize;
}

int getNumOfEven(Queue queue)
{
    int even = queue.list->numOfEven; // access size member of struct
    return even;
}

void printQueue(Queue queue)
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
            printf(" %d ", p->age);
            p = p->nextPtr;
        }
    }
}

void emptyQueue(Queue queue)
{
    Student * p;
    p = queue.list->head;  // set running node to beginning of list
    while(p != NULL)
    {
        queue.list->head = p->nextPtr;
        free(p); // free p
        p = queue.list->head;
    }
    free(queue.list); // free head
}
