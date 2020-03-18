#include <stdio.h>
#include <stdlib.h>

typedef struct nodestruct
{
    int data;
    struct nodestruct *next;
} Node;

typedef struct liststruct
{
    Node * head;
    Node * tail;
} List;

List * createList();
int insertAtHead(int, List *);
int insertAtTail(int, List *);
void printList(List *);
int getListLength(List *);
List * copyList(List *);
void freeList(List *);

int main()
{
    List * list = createList();
    insertAtHead(1, list); 
    insertAtHead(2, list); 
    insertAtHead(3, list); 
    insertAtHead(4, list); 
    insertAtHead(5, list); 

    insertAtTail(6, list);
    insertAtTail(7, list);
    insertAtTail(8, list);
    insertAtTail(9, list);
    insertAtTail(10, list);

    int size = getListLength(list);
    printf("Linked List Size: %d\n\n", size);

    // print list contents
    printList(list);

    // test copy list
    List * newCopy = copyList(list);
    printf("Copied ");
    printList(newCopy);

    freeList(list);
    return 0;
}

// this function creates an empty list
List * createList()
{
    // create list
    List * list = malloc(sizeof(List));
    if(list == NULL)
    {
        printf("Memory could not be allocated.\n");
    }
    // set head and tail to NULL
    list->head = NULL;
    list->tail = NULL;

    return list; // return beginning of empty list
}

/* this function inserts a node at the 
   beginning of the list, returns 0 if
   successful or 1 if failed. */
int insertAtHead(int data, List * list)
{
    Node * newHead = malloc(sizeof(Node)); // create new node for newHead
    if(newHead == NULL)
    {
        printf("Memory could not be allocated.\n");
        return 1;
    }
    // set data value of newHead
    newHead->data = data;

    if(list->head == NULL) // if head is still NULL (no nodes created)
    {
        // set newHead to head value
        list->head = newHead; 
        list->tail = newHead;       
        // set next pointer to NULL
        newHead->next = NULL;
    }
    else // add newHead to list
    {
        newHead->next = list->head; // set next to point to original head
        list->head = newHead; // set original head to newHead
    }
    return 0; // success
}

int insertAtTail(int data, List * list)
{
    Node * newTail = malloc(sizeof(Node));
    if(newTail == NULL)
    {
        printf("Memory could not be allocated");
        return 1;
    }

    // set newTail data and newTail->next
    newTail->data = data;
    newTail->next = NULL;

    if (list->tail == NULL) // no tail set
    {
        list->head = newTail;
        list->tail = newTail;
    }
    else
    {
        list->tail->next = newTail; // set next of previous tail to point to newTail
        list->tail = newTail; // set newTail to tail
    }
    return 0;
}

void printList(List * list) 
{
    // list is EMPTY
    if(list == NULL)
    {
        printf("List is empty. Please create nodes then print.\n");
    }

    Node * p = list->head; // create running pointer
    printf("Linked List Contents:");
    while (p != NULL) // when list is not empty
    {
        printf(" %d", p->data); // print data
        p = p->next; // move running pointer
    }
    printf("\n\n");
} 

int getListLength(List * list)
{
    Node * p = list->head; // set running pointer to beginning of list
    int count = 0; // initialize counter
    while (p != NULL) // run through list
    {
        count++; // add one to count
        p = p->next; // move running pointer
    }
    return count; // return count
}

List * copyList(List * list)
{
    // create new empty list
    List * cpyList = createList();

    Node * p; // create running pointer
    p = list->head; // set pointer to beginning to list
    while(p != NULL)
    {
        insertAtTail(p->data, cpyList); // data at pointer and new list
        p = p->next; // move pointer
    }
    return cpyList; // return new list
}

void freeList(List * list)
{
   Node * p = list->head;
    while(p != NULL)
    {
        free(p);
        p = p->next; // move pointer up one
    }
    free(list); // free head pointer
}
