#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct studstruct{
    int age;
    struct studstruct *nextPtr;
}Student;

Student* initListWithDummyNode();
int insertToHead(Student*,int);
int insertToTail(Student*,int);
void printList(Student*);
void emptyList(Student*);
void freeList(Student*);

/* this function initializes a list
   with two dummy nodes at the head
   and tail of the list. returns list */
Student * initListWithDummyNode()
{
    // malloc head and tail nodes
    Student * dummyHead = malloc(sizeof(Student));
    Student * dummyTail = malloc(sizeof(Student));
    // malloc checking head and tail nodes
    if(dummyHead == NULL || dummyTail == NULL)
    {
        printf("Memory could not be allocated.\n");
        return NULL;
    }
    else
    {
        dummyHead->nextPtr = dummyTail; // point head to tail node
        dummyTail->nextPtr = NULL; // set tail->nextPtr of dummy to NULL
    }
    return dummyHead; // pass back beginning of empty list
}

/* function allows a new node to be added
   to the beginning of the linked list. */
int insertToHead(Student * head, int ageToInsert)
{
    // create new node forage insertion
    Student * newHead = malloc(sizeof(Student));
    if(newHead == NULL)
    {
        printf("Memory could not be allocated.\n");
        return 1;
    }
    else
    {
        // insertage into newHead node
        newHead->age = ageToInsert; 
        // set nextPtr pointer of new to original head->nextPtr pointer
        newHead->nextPtr = head->nextPtr; 
        // change head->nextPtr to store address of newNode
        head->nextPtr = newHead; // newHead is *
        return 0;
    }
}

/* function allows a new node to be added
   to the end of the linked list. */
int insertToTail(Student * head, int age)
{
    Student * newTail = malloc(sizeof(Student));
    if(newTail == NULL)
    {
        printf("Memory could not be allocated.\n");
        return 1;
    }
    else
    {
        Student * p = head; // set running pointer to beginning of list

        while(p->nextPtr->nextPtr != NULL) // go through list, find node before dummy
        {
            p = p->nextPtr;
        }
        newTail->age = age; // insert age to newTail node
        newTail->nextPtr = p->nextPtr; // set new tail pointer to current pointer position
        p->nextPtr = newTail; // point previous tail node (not dummy) to new Tail
        return 0;
    }
}

/* this function prints the contents
   of this list passed in */ 
void printList(Student * list)
{
    printf("Linked List Ages: ");
    Student * p;
    p = list; // set p to beginning of list 

    p = p->nextPtr; // move pointer up one (skip dummy node)
	while(p->nextPtr != NULL)
	{
		printf("%d  ", p->age);
        if(p->nextPtr->nextPtr == NULL) // avoid printing tail dummy node
        {
            break;
        }
		p = p->nextPtr; // print until break
	}
}

/* this function deletes nodes in linked list,
   leaving dummy nodes at the addresses they were
   at previously */
void emptyList(Student * list)
{
    // int i = 1; // test loop
    Student * p; // create running pointer
    p = list; // set pointer to beginning of list
    p = p->nextPtr; // skip head dummy node
    while(p != NULL)
    {
        if(list->nextPtr->nextPtr == NULL) // at dummy node
        {
            break;
        }
        else
        {
            // printf("\n%d address of p free = %p", i, p);
            p = list;
            list = list->nextPtr; // move pointer up one
            free(p);
            // printf("\nfinished free #%d\n", i);
            // i++;
        }
    }
}

/* this function frees all memory allocated
   from the list passed in */
void freeList(Student * list)
{
    Student * p;
    while (list != NULL) 
    {
        p = list;
        list = list->nextPtr;
        free(p);
    }
}
