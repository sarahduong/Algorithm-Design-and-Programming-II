#include <stdio.h>
#include <stdlib.h>

/* single node for employee containing
   data and next pointer */
typedef struct empStruct
{
    int data;
    struct empStruct * next;
} Employee;

/* struct containing queue info, including
   head node, tail node, and size of queue */
typedef struct qInfo
{
    int size;
    Employee * head;
    Employee * tail;
} qInfo;

/* struct containing pointer to queue info */
typedef struct qStruct
{
    qInfo * qPtr;
} Queue;

// Function Prototypes
Queue initQueue();
int enqueue(Employee *, Queue);
Employee * dequeue(Queue);
int getQsize(Queue);
void printQueue(Queue);
void freeQueue(Queue);

int main()
{
    Queue list = initQueue();
    Employee * empNode;
    enqueue(empNode, list);
    enqueue(empNode, list);
    enqueue(empNode, list);
    enqueue(empNode, list);
    printf("Nodes enqueued\n\n");
    printQueue(list);
    dequeue(list);
    printf("Node dequeued");
    printQueue(list);
    getQsize(list);
}

/* this function creates a queue and
   returns an empty queue */
Queue initQueue()
{
    Queue newQ; // create new queue
    newQ.qPtr = malloc(sizeof(qInfo)); // malloc queue pointer
    newQ.qPtr->size = 0; // set size of queue to 0 (empty)
    newQ.qPtr->head = newQ.qPtr->tail; // set head node equal to tail

    newQ.qPtr->head = NULL; // set head to NULL
    newQ.qPtr->tail = NULL; // set tail to NULL
    return newQ;
}

// enqueue returns an int error code
int enqueue(Employee * newNode, Queue list)
{
    newNode = malloc(sizeof(Employee)); // malloc emplyee node passed in
    if(newNode == NULL)
    {
        printf("Memory could not be allocated\n");
        return 1;
    }
    else
    {
        newNode->data = list.qPtr->size; // set data for newNode (equal to size in this case)
        newNode->next = NULL; // set next pointer to NULL

        if(list.qPtr->tail == NULL) // if tail is NULL (empty list)
        {
            // set head and tail node equal to new node
            list.qPtr->head = newNode;
            list.qPtr->tail = newNode;
            // increase size of queue by one
            list.qPtr->size++;
        }
        else // if list is not empty
        {
            list.qPtr->tail->next = newNode; // move tail ptr up one, set to newNode
            list.qPtr->tail = newNode; // set new tail to newNode/newtail
            list.qPtr->size++; // increase size of queue      
        }
        return 0; // successful enqueue
    }
}

Employee * dequeue(Queue list)
{
    Employee * p = list.qPtr->head;
    list.qPtr->head = p->next;
    list.qPtr->size--;
    return p;
}

// returns # of items in queue
int getQsize(Queue list)
{
    return list.qPtr->size; // access size member of struct
}

void printQueue(Queue list)
{
    Employee * p;
    p = list.qPtr->head;
    while (p != NULL)
    {
        printf(" %d ", p->data);
        p = p->next;
    }
}

/* this function frees all allocated memory */
void freeQueue(Queue list)
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
