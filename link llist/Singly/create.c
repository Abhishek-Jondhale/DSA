// #include <stdio.h>
// #include <stdlib.h>

// /* Structure of a node */
// struct node {
//     int data;          // Data 
//     struct node *next; // Address 
// }*head;


// /* 
//  * Functions to create and display list
//  */
// void createList(int n);
// void traverseList();


// int main()
// {
//     int n;

//     printf("Enter the total number of nodes: ");
//     scanf("%d", &n);

//     createList(n);

//     printf("\nData in the list \n");
//     traverseList();

//     return 0;
// }

// /*
//  * Create a list of n nodes
//  */
// void createList(int n)
// {
//     struct node  *newNode, *temp;
//     int data, i;

//     head = (struct node *)malloc(sizeof(struct node));

//     // Terminate if memory not allocated
//     if(head == NULL)
//     {
//         printf("Unable to allocate memory.");
//         exit(0);
//     }


//     // Input data of node from the user
//     printf("Enter the data of node 1: ");
//     scanf("%d", &data);

//     head->data = data; // Link data field with data
//     head->next = NULL; // Link address field to NULL


//     // Create n - 1 nodes and add to list
//     temp = head;
//     for(i=2; i<=n; i++)
//     {
//         newNode = (struct node *)malloc(sizeof(struct node));

//         /* If memory is not allocated for newNode */
//         if(newNode == NULL)
//         {
//             printf("Unable to allocate memory.");
//             break;
//         }

//         printf("Enter the data of node %d: ", i);
//         scanf("%d", &data);

//         newNode->data = data; // Link data field of newNode
//         newNode->next = NULL; // Make sure new node points to NULL 

//         temp->next = newNode; // Link previous node with newNode
//         temp = temp->next;    // Make current node as previous node
//     }
// }



// /*
//  * Display entire list
//  */
// void traverseList()
// {
//     struct node *temp;

//     // Return if list is empty 
//     if(head == NULL)
//     {
//         printf("List is empty.");
//         return;
//     }
    
//     temp = head;
//     while(temp != NULL)
//     {
//         printf("Data = %d\n", temp->data); // Print data of current node
//         temp = temp->next;                 // Move to next node
//     }
// }



// #include<stdio.h>
// #include<stdlib.h>
// struct node{
//     int data;
//     struct node *link;
// };
// int main(){
//     struct node *head=NULL;
//     head=(struct node *)malloc(sizeof(struct node));
//     head->data=50;
//     head->link=NULL;
//     printf("%d",head->data);
//     return 0;
// }

    #include<stdio.h>
    #include<stdlib.h>

    int main()
    {
    //node structure
    struct node
    {
        int data;
        struct node *next;
    };

    //declaring nodes
    struct node *head,*middle,*last;

    //allocating memory for each node
    head   = malloc(sizeof(struct node));
    middle = malloc(sizeof(struct node));
    last   = malloc(sizeof(struct node));

    //get input from user for head node
    printf("Enter data for head node: ");
    scanf("%d",&head->data);

    //get input from user for middle node
    printf("Enter data for middle node: ");
    scanf("%d",&middle->data);

    //get input from user for last node
    printf("Enter data for last node: ");
    scanf("%d",&last->data);

    //connecting each nodes. head->middle->last
    head->next   = middle;
    middle->next = last;
    last->next   = NULL;

    //temp is a reference for head pointer.
    struct node *temp = head;

    //till the node becomes null, printing each nodes data
    while(temp != NULL)
    {
        printf("Data = %d\n",temp->data);
        temp = temp->next;
    }
    

    return 0;
    }


// #include<stdio.h>
// #include<stdlib.h>
// int main(){


// struct node
// {
//     int data;
//     struct node *next; 
// };
// struct node *head,*middle,*last;

// head=malloc(sizeof(struct node));
// middle=malloc(sizeof(struct node));
// last=malloc(sizeof(struct node));
// printf("Enter the data of head node: ");
// scanf("%d",&head->data);

// printf("Enter the data of middle node: ");
// scanf("%d",&middle->data);

// printf("Enter the data of last node: ");
// scanf("%d",&head->data);

// head->next=middle;
// middle->next=last;
// last->next=NULL;

// struct node *temp=head;


// while (temp!=NULL)
// {
//     printf("Data=%d\n",temp->data);
//     temp= temp->next;
// }
// return 0;




// }
