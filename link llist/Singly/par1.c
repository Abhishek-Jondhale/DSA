#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void addFirst(struct node **head, int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;

 
    newNode->next = *head;

    *head = newNode;
}

void printList(struct node *head)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        printf("Data = %d\n", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *head = NULL;
    int n;

   
    printf("Enter the total number of nodes: ");
    scanf("%d", &n);

  
    for(int i = 0; i < n; i++)
    {
        int val;
        printf("Enter the data of node %d: ", i + 1);
        scanf("%d", &val);
        addFirst(&head, val);
    }

    //print the linked list
    printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    printList(head);

    //prompt the user to enter the data to be inserted
    int val;
    printf("Enter data to insert at beginning of the list: ");
    scanf("%d", &val);

    //insert the node
    addFirst(&head, val);

    //print the linked list again
    printf("DATA INSERTED SUCCESSFULLY\n");
    printf("Data in the list\n");
    printList(head);

    return 0;
}