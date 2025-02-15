/**
 * C program to create and traverse Circular Linked List
 */
#include <stdio.h>
#include <stdlib.h>


/*
 * Basic structure of Node
 */
struct node {
    int data;
    struct node * next;
}*head;


/*
 * Functions used in this program
 */
void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void deleteAtFirst();
void deleteAtLast();


int main()
{
    int n, data, choice=1;

    head = NULL;

    /*
     * Run forever until user chooses 0
     */
    while(choice != 0)
    {
        printf("============================================\n");
        printf("CIRCULAR LINKED LIST PROGRAM\n");
        printf("============================================\n");
        printf("1. Create List\n");
        printf("2. Display list\n");  
        printf("3. Insert At Beginning\n");
        printf("4. Insert At End\n");
        printf("5. Delete At First\n");
        printf("6. Delete At Last\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Enter data to be inserted at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 4:
                printf("Enter data to be inserted at End: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 5:
                deleteAtFirst();
                break;
            case 6:
                deleteAtLast();
                break;  
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-2");
        }

        printf("\n\n\n\n\n");
    }

    return 0;
}


/**
 * Creates a circular linked list of n nodes.
 * @n Number of nodes to be created
 */
void createList(int n)
{
    int i, data;
    struct node *prevNode, *newNode;

    if(n >= 1)
    {
        /*
         * Creates and links the head node
         */
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        prevNode = head;

        /*
         * Creates and links rest of the n-1 nodes
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            // Link the previous node with newly created node
            prevNode->next = newNode;

            // Move the previous node ahead
            prevNode = newNode;
        }

        // Link the last node with first node
        prevNode->next = head;

        printf("\nCIRCULAR LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/**
 * Display the content of the list
 */
void displayList()
{
    struct node *current;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        current = head;
        printf("DATA IN THE LIST:\n");

        do {
            printf("Data %d = %d\n", n, current->data);

            current = current->next;
            n++;
        }while(current != head);
    }
}

void insertAtBeginning(int data)
{
    struct node *newNode, *current;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        /*
         * Creates new node, assign data and links it to head
         */
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;

        /*
         * Traverses to last node and links last node
         * with first node which is new node
         */
        current = head;
        while(current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;

        /*Makes new node as head node*/
        head = newNode;

        printf("NODE INSERTED SUCCESSFULLY\n");
    }
}

void insertAtEnd(int data){
    struct node *newNode, *current;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
       
        current = head;
        while(current->next != head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = head;

        /*Makes new node as head node*/

        printf("NODE INSERTED SUCCESSFULLY\n");
    }
}
void deleteAtFirst() {
    if (head == NULL) {
        printf("Unable to delete. List is empty.\n");
        return;
    }

    struct node* toDelete = head;
   
        struct node* current = head;
        while (current->next != head) {
            current = current->next;
        }
        head = head->next;
        current->next = head;
   

    free(toDelete);
    printf("SUCCESSFULLY DELETED NODE AT THE BEGINNING OF THE LIST.\n");
}

void deleteAtLast() {
    if (head == NULL) {
        printf("Unable to delete. List is empty.\n");
        return;
    }

    struct node* current = head;
    struct node* previous = NULL;

    while (current->next != head) {
        previous = current;
        current = current->next;
    }

    if (previous != NULL) {
        previous->next = head; // Update the last node to point to the new head
    } else {
        head = NULL; // If there was only one node, set the head to NULL
    }
    free(current);
    printf("SUCCESSFULLY DELETED THE LAST NODE.\n");
}