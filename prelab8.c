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
void printList(List *);  


int main(void)
{
    // create pointer to node to store beginning node address
    List * head;

    /* call function to set head to beginning 
    address of head node (points to head node) */
    head = initIntegerList();

    // create data set by adding data to list
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);

    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    insertAtTail(head, 10);

    printList(head);
    //freeList(head);
   
    return 0;
}

/* function creates an empty linked list
   with NULLed data. Does not have anything 
   passed in. Returns linked list with pointer
   to head/beginning node */
List * initIntegerList()
{
    // create & malloc size for head node
    List * head = malloc(sizeof(List));
    
    // set data in List to NULL
    head->data = '\0';
    head->next = NULL;
    
    // return empty linked list
    return head;
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
        // insert data to newTail node
        newTail->data = newData;

        /* if address to next node is not NULL,
        move node up */
        while(head->next != NULL)
        {
            head = head->next;
        }
        /* found the NULL next pointer (last node), 
        set next pointer to point to newTail node */
        head->next = newTail;
    
        // NULL pointer after tail node (since it is at the end)
        newTail->next = NULL;
        return 0;
    }
}

void printList(List * head)
{
    printf("Linked List Data: ");

    List * p;

    p = head; // set p to beginning of list 
	while(p != NULL)
	{
		printf("%d  ", p->data);
		p = p->next; // print until
	}
}

void freeList(List * headNode)
{
    List * p;
    while(headNode != NULL)
    {
        p = headNode; // set p to headPtr
        headNode = headNode->next;  // set headNode to nextPtr
        free(p); // free node
        p = NULL; // set node to null
    }
}
