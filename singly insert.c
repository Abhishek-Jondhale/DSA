#include <stdio.h>
#include <stdlib.h>


/* Structure of a node */
struct node {
    int data;          // Data 
    struct node *next; // Address 
}*head;


void createList(int n);
void insertNodeAtBeginning(int data);
void insertNodeAtEnd(int data);
void insertNodeAtMiddle(int data, int position);
void displayList();


int main()
{
    int n, data, position,choice=1;
    
    
	while(choice != 0)
	{
	printf("1:create list \n");
	printf("2:display list \n");
	printf("3:insert at beginning \n");
	printf("4:insert at last \n");
	printf("5:insert in between \n");
	printf("\n Enter your choice");
	scanf("%d",&choice);
	
	switch(choice)
	{
	case 1:
	printf("Enter the total number of nodes: ");
    scanf("%d", &n);
    createList(n);
		break;
		
		
	case 2:
		printf("\nData in the list \n");
    displayList();
		break;
		
		
	case 3:
	printf("\nEnter data to insert at beginning of the list: ");
    scanf("%d", &data);
    insertNodeAtBeginning(data);
		break;
		
		
	case 4:
	
printf("\nEnter data to insert at end of the list: ");
    scanf("%d", &data);
    insertNodeAtEnd(data);
		break;
		
		
	case 5:
		printf("nEnter data to insert at middle of the list: ");
    scanf("%d", &data);
    printf("Enter the position to insert new node: " );
    scanf("%d", &position);
    insertNodeAtMiddle(data, position);
		break;
   

    default:
    printf("Error! Invalid choice. Please choose between 0-5");
}
printf("\n\n");
}
return 0;
}


/*
 * Create a list of n nodes
 */
void createList(int n)
{
    struct node *newNode, *temp;
    int data, i;

    head = (struct node *)malloc(sizeof(struct node));

    /*
     * If unable to allocate memory for head node
     */
    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        /*
         * Input data of node from the user
         */
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link data field with data
        head->next = NULL; // Link address field to NULL

        temp = head;

        /*
         * Create n nodes and adds to linked list
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            /* If memory is not allocated for newNode */
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);

                newNode->data = data; // Link data field of newNode with data
                newNode->next = NULL; // Link address field of newNode with NULL

                temp->next = newNode; // Link previous node i.e. temp to the newNode
                
                temp = temp->next; 
            }
        }

        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}


/*
 * Create a new node and inserts at the beginning of the linked list.
 */
void insertNodeAtBeginning(int data)
{
    struct node *newNode;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = head; // Link address part

        head = newNode;          // Make newNode as first node

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}


/*
 * Create a new node and inserts at the end of the linked list.
 */
void insertNodeAtEnd(int data)
{
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link the data part
        newNode->next = NULL; 

        temp = head;

        // Traverse to the last node
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;

        temp->next = newNode; // Link address part

        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}



/*
 * Creates a new node and inserts at middle of the linked list.
 */
void insertNodeAtMiddle(int data, int position)
{
    int i;
    struct node *newNode, *temp;

    newNode = (struct node*)malloc(sizeof(struct node));

    if(newNode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        newNode->data = data; // Link data part
        newNode->next = NULL;

        temp = head;

        /* 
         * Traverse to the n-1 position 
         */
        for(i=2; i<=position-1; i++)
        {
            temp = temp->next;

            if(temp == NULL)
                break;
        }

        if(temp != NULL)
        {
            /* Link address part of new node */
            newNode->next = temp->next; 

            /* Link address part of n-1 node */
            temp->next = newNode;

            printf("DATA INSERTED SUCCESSFULLY\n");
        }
        else
        {
            printf("UNABLE TO INSERT DATA AT THE GIVEN POSITION\n");
        }
    }
}


/*
 * Display entire list
 */
void displayList()
{
    struct node *temp;

    /*
     * If the list is empty i.e. head = NULL
     */
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}
