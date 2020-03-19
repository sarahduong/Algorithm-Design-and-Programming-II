#include <stdio.h>
#include <stdlib.h>

typedef struct listStruct
{
    int data;
    struct listStruct * next;
} List;

List * initIntegerList();
int insertAtHead(List *, int);
int insertAtTail(List *, int);
List * copyList(List *);
void printList(List *);
void freeList(List *);

int main(void)
{
    // create pointer to node to store beginning node address
    List * list;

    /* call function to set head to beginning 
    address of head node (points to head node) */
    list = initIntegerList();

    // create data set by adding data to list
    insertAtHead(list, 1);
    insertAtHead(list, 2);
    insertAtHead(list, 3);
    insertAtHead(list, 4);
    insertAtHead(list, 5);

    insertAtTail(list, 6);
    insertAtTail(list, 7);
    insertAtTail(list, 8);
    insertAtTail(list, 9);
    insertAtTail(list, 10);

    printList(list);

    // test copy list
    List * newCopy = copyList(list);
    printf("\nCopied ");
    printList(newCopy);
    printf("\n");

    freeList(list);
    freeList(newCopy);
   
    return 0;
}

/* function creates an empty linked list
   with NULLed data. Does not have anything 
   passed in. Returns NULL */
List * initIntegerList()
{
    // malloc head and tail nodes
    List * dummyHead = malloc(sizeof(List));
    List * dummyTail = malloc(sizeof(List));
    // malloc checking head and tail nodes
    if(dummyHead == NULL || dummyTail == NULL)
    {
        printf("Memory could not be allocated.\n");
        return NULL;
    }
    else
    {
        dummyHead->next = dummyTail; // point head to tail node
        dummyTail->next = NULL; // set tail->next of dummy to NULL
    }
    return dummyHead; // pass back beginning of empty list
}

/* function allows a new node to be added
   to the beginning of the linked list. */
int insertAtHead(List * head, int dataToInsert)
{
    // create new node for data insertion
    List * newHead = malloc(sizeof(List));
    if(newHead == NULL)
    {
        printf("Memory could not be allocated.\n");
        return 1;
    }
    else
    {
        // insert data into newHead node
        newHead->data = dataToInsert; 
        // set next pointer of new to original head->next pointer
        newHead->next = head->next; 
        // change head->next to store address of newNode
        head->next = newHead; // newHead is *
        return 0;
    }
}

/* function allows a new node to be added
   to the end of the linked list. */
int insertAtTail(List * head, int newData)
{
    List * newTail = malloc(sizeof(List));
    if(newTail == NULL)
    {
        printf("Memory could not be allocated.\n");
        return 1;
    }
    else
    {
        List * p = head; // set running pointer to beginning of list

        while(p->next->next != NULL) // go through list, find node before dummy
        {
            p = p->next;
        }
        newTail->data = newData; // insert data to newTail node
        newTail->next = p->next; // set new tail pointer to current pointer position
        p->next = newTail; // point previous tail node (not dummy) to new Tail
        return 0;
    }
}

void printList(List * list)
{
    printf("Linked List Data: ");
    List * p;
    p = list; // set p to beginning of list 

    p = p->next; // move pointer up one (skip dummy node)
	while(p->next != NULL)
	{
		printf("%d  ", p->data);
        if(p->next->next == NULL) // avoid printing tail dummy node
        {
            break;
        }
		p = p->next; // print until break
	}
}


List * copyList(List * list)
{
    // create new empty list
    List * cpyList = initIntegerList();

    List * p; // create running pointer

    p = list; // set pointer to beginning of list
    p = p->next; // skip head dummy node
    while(p->next!= NULL)
    {
        insertAtTail(cpyList, p->data); // data at pointer and new list
        if(p->next->next == NULL) // do not copy tail dummy node
        {
            break;
        }
        p = p->next; // move pointer
    }
    return cpyList; // return new list
}

void freeList(List * head)
{
    printf("Linked List Data: ");

    List * p; // create running pointer

    p = head; // set p to beginning of list 
	while(p != NULL) // loop when not at end of list
	{
		printf("%d  ", p->data); // print data
		p = p->next; // move to next mode
	}
}


