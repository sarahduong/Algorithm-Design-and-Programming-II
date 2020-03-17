#include <stdio.h>
#include <stdlib.h>

typedef struct listStruct
{
    int data;
    struct listStruct * next;
} List;

// Function Prototypes
List * initIntegerList();                
List * insertAtHead(List *, int);
List * insertAtTail(List *, int);
void printList(List *);
void freeList(List *);

int main(void)
{
    /* call function to set head to beginning 
    address of head node (points to head node) */
    List * head = initIntegerList();

    // create data set by adding data to list
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    head = insertAtHead(head, 3);
    head = insertAtHead(head, 4);
    head = insertAtHead(head, 5);

    head = insertAtTail(head, 6);
    head = insertAtTail(head, 7);
    head = insertAtTail(head, 8);
    head = insertAtTail(head, 9);
    head = insertAtTail(head, 10);

    printList(head);
    freeList(head);
   
    return 0;
}

/* function creates an empty linked list
   with NULLed data. Does not have anything 
   passed in. Returns NULL */
List * initIntegerList()
{
    return NULL; // pass back NULL value for head (empty list)
}

/* this function allows a new node to be added
   to the beginning of the linked list. */
List * insertAtHead(List * head, int dataToInsert)
{
    // create new node for data insertion
    List * newHead = malloc(sizeof(List));
    if(newHead == NULL)
    {
        printf("Memory could not be allocated.\n");
        return newHead;
    }
    else
    {
        newHead->data = dataToInsert; // insert data to newHead node

        if(head == NULL) // head NULL if no nodes created yet
        {
            head = newHead; // set head to malloced newHead node (newHead malloced already)
            head->next = NULL; // null next pointer (singular node "list")
            return head; // return node to beginning
        }
        else // if list is not empty
        {
            // point newHead->next to previous head
            newHead->next = head;          
            return newHead;
        }
    }
}

/* 
List * insertAtHead
{

    List * newHead = malloc(sizeof(List));

    if(newHead != NULL) //malloc check
    {
        newHead->data = dataToInsert;
        newHead->next = head;  
        return newHead;
    }
    else // malloc failed
    {
        printf("Memory could not be allocated.\n");
        return head;
    }
}
*/

/* this function allows a new node to be added
   to the end of the linked list. */
List * insertAtTail(List * head, int newData)
{
    if(head == NULL)
    {
        printf("No nodes allocated - empty list. Create head node first before inserting tail.\n");
        return NULL;
    }
    else
    {
        // malloc newTail node
        List * newTail = malloc(sizeof(List));
        if(newTail == NULL)
        {
            printf("Memory could not be allocated.\n");
            return newTail;
        }
        else
        {    
            // insert data to newTail node
            newTail->data = newData;
            newTail->next = NULL;

            List * p = head; // create running node
            while(p->next != NULL) // move p to end of list
            {
                p = p->next;
            }
            /* found the NULL next pointer (last node), set 
            original tail next pointer to point to newTail node */
            p->next = newTail;
        
            // return updated list
            return head;
        }
    }
}

/* this function creates a moving pointer that starts
   at the head node, and prints data from the node and
   moves it up one until the list is at the end/NULL */
void printList(List * head)
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

/* this function creates a holding pointer that is set to 
   the address of the head node and frees it. It moves the 
   pointer up one until it reaches the end of the list (NULL) */
void freeList(List * head)
{
    List * p = head; // set running pointer to start at head

    while(p != NULL) // loop while list has not ended
    {
        head = p; // set head to running ptr
        p = p->next; // move up one
        free(head); // free head
    }
    head = NULL;
}
