#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct
{
    int age;
    struct studstruct * nextPtr;
} Student;

typedef struct linkedlist
{
    Student * head, * tail;
} StudentList;

StudentList * initStack()
{
    // create list
    StudentList * list = malloc(sizeof(StudentList));
    if(list == NULL)
    {
        printf("Memory could not be allocated.\n");
    }
    // set head and tail to NULL
    list->head = NULL;
    list->tail = NULL;

    return list; // return beginning of empty list 
}

int pushStack(StudentList * list,int dataToInsert)
{
    Student * newNode = malloc(sizeof(Student)); // create new node for newHead
    if(newNode == NULL)
    {
        printf("Memory could not be allocated.\n");
        return -1; // insertion could not be conpleted
    }
    // set data value of newNode
    newNode->age = dataToInsert;

    if(list->head == NULL) // if head is still NULL (no nodes created)
    {
        // set newNode to head value
        list->head = newNode; 
        list->tail = newNode;       
        // set next pointer to NULL
        newNode->nextPtr = NULL;
    }
    else // add newNode to list
    {
        newNode->nextPtr = list->head; // set next to point to original head
        list->head = newNode; // set original head to newHead
    }
    return 1; // successfully completed insertion 
}

Student * popStack(StudentList* list)
{
    if(list == NULL) // if list is empty
    {
        printf("Stack could not be popped.\n");
        return NULL; // stack could not be popped
    }
    else
    {
        Student * p; // create holding pointer
        p = list->head; // set holding to head of list
        list->head = p->nextPtr; // set head node of list to node after head
        return p; // return holding node
    }
}

StudentList * initQueue()
{
    // create list
    StudentList * list = malloc(sizeof(StudentList));
    if(list == NULL)
    {
        printf("Memory could not be allocated.\n");
    }
    // set head and tail to NULL
    list->head = NULL;
    list->tail = NULL;

    return list; // return beginning of empty list 
}

int enQueue(StudentList * list, int dataToQueue)
{
    Student * newNode = malloc(sizeof(Student));
    if(newNode == NULL)
    {
        printf("Memory could not be allocated");
        return -1;
    }

    // set newNode data and newNode->next
    newNode->age = dataToQueue;
    newNode->nextPtr = NULL;

    if (list->tail == NULL) // no tail set
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->nextPtr = newNode; // set next of previous tail to point to newTail
        list->tail = newNode; // set newTail to tail
    }
    return 1;
}

Student * deQueue(StudentList* list)
{
    if(list == NULL) // if list is empty
    {
        printf("Stack could not be popped.\n");
        return NULL; // list could not be dequeued
    }
    else
    {
        Student * p; // create holding pointer
        p = list->head; // set holding to head of list
        list->head = p->nextPtr; // set head node of list to node after head
        return p; // return holding node
    }
}

void printList(StudentList* list)
{
    // list is EMPTY
    if(list == NULL)
    {
        printf("List is empty. Please create nodes then print.\n");
    }

    Student * p = list->head; // create running pointer
    printf("List Contents:");
    while (p != NULL) // when list is not empty
    {
        printf(" %d", p->age); // print data
        p = p->nextPtr; // move running pointer
    }
    printf("\n\n");
}

void freeList(StudentList* list)
{
    Student * p = list->head;
    while(p != NULL)
    {
        list->head = p->nextPtr;
        free(p);
        p = list->head;
    }
    free(list); // free head
}

int main()
{
    printf("\n***STACK TEST***\n");
    StudentList * list = initStack();
    printf("Pushed Stack ");
    pushStack(list, 1);
    pushStack(list, 2);
    pushStack(list, 3);
    pushStack(list, 4);
    pushStack(list, 5);
    pushStack(list, 6);
    pushStack(list, 7);
    pushStack(list, 8);
    pushStack(list, 9);
    pushStack(list, 10);
    printList(list);
    popStack(list);
    printf("Popped Stack ");
    printList(list);

    printf("\n***QUEUE TEST***\n");
    StudentList * listQ = initQueue(); // create queue
    printf("Enqueued ");
    enQueue(listQ, 1);
    enQueue(listQ, 2);
    enQueue(listQ, 3);
    enQueue(listQ, 4);
    enQueue(listQ, 5);
    enQueue(listQ, 6);
    enQueue(listQ, 7);
    enQueue(listQ, 8);
    enQueue(listQ, 9);
    enQueue(listQ, 10);
    printList(listQ);
    deQueue(listQ);
    printf("Dequeued ");
    printList(listQ);

    freeList(list);
    freeList(listQ);
}
