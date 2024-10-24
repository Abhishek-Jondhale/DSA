/**
 * C program to insert a node in Doubly linked list
 */
#include <stdio.h>
#include <stdlib.h>
/*
 * Basic structure of Node
 */
struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head, *last;
/*
 * Function used in this program
 */
void createList(int n);
void displayList();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void deleteFromBeginning();
void deleteFromEnd();
int main()
{
    int n, data, choice = 1;
    head = NULL;
    last = NULL;
    while (choice != 0)
    {
        printf("1. Create List\n");
        printf("2. Insert node - at beginning\n");
        printf("3. Insert node - at end\n");
        printf("4. Delete node - at beginning\n");
        printf("5. Delete node - at end\n");
        printf("6. Display list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the total number of nodes in list: ");
            scanf("%d", &n);
            createList(n);
            break;
        case 2:
            printf("Enter data of first node : ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 3:
            printf("Enter data of last node : ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 4:
            deleteFromBeginning();
            break;
        case 5:
            deleteFromEnd();
            break;
        case 6:
            displayList();
            break;
        case 0:
            break;
        default:
            printf("Error! Invalid choice. Please choose between 0-5");
        }
        printf("\n\n\n");
    }
    return 0;
}
/**
 * Creates a doubly linked list of n nodes.
 * @n Number of nodes to be created
 */
void createList(int n)
{
    int i, data;
    struct node *newNode;
    if (n >= 1)
    {
        /*
         * Create and link the head node
         */
        head = (struct node *)malloc(sizeof(struct node));
        printf("Enter data of 1 node: ");
        scanf("%d", &data);
        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;
        /*
         * Create and link rest of the n-1 nodes
         */
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of %d node: ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->prev = NULL; // Link new node with the previous node
            newNode->next = NULL;
            last->next = newNode;
            newNode->prev = last; // Link previous node with the new node
            last = newNode;       // Make new node as last/previous node
        }
        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
/**
 * Display content of the list from beginning to end
 */
void displayList()
{
    struct node *temp;
    int n = 1;
    if (head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");
        while (temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}
/**
 * Inserts a new node at the beginning of the doubly linked list
 * @data Data of the first node i.e. data of the new node
 */
void insertAtBeginning(int data)
{
    struct node *newNode;
    if (head == NULL)
    {
        printf("Error, List is Empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head; // Point to next node which is currently head

        newNode->prev = NULL; // Previous node of first node is NULL
        /* Link previous address field of head with newnode */
        head->prev = newNode;
        /* Make the new node as head node */
        head = newNode;
        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
    }
}
/**
 * Inserts a new node at the end of the doubly linked list
 * @data Data of the last node i.e data of the new node
 */
void insertAtEnd(int data)
{
    struct node *newNode;
    if (last == NULL)
    {
        printf("Error, List is empty!\n");
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
        printf("NODE INSERTED SUCCESSFULLY AT THE END OF LIST \n");
    }
}
void deleteFromBeginning()
{
    struct node *toDelete;
    if (head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    {
        toDelete = head;
        head = head->next; // Move head pointer to 2 node
        if (head != NULL)
            head->prev = NULL; // Remove the link to previous node
        free(toDelete);        // Delete the first node from memory
        printf("SUCCESSFULLY DELETED NODE BEGINNING OF THE LIST.\n");
    }
}
void deleteFromEnd()
{
    struct node *toDelete;
    if (last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;
        last = last->prev; // Move last pointer to 2nd last node
        if (last != NULL)
            last->next = NULL; // Remove link to of 2nd last node with last node

        free(toDelete); // Delete the last node
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
    }
}