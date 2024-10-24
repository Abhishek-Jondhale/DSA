#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void create();
void display();
void search();
void insertFirst();
void insertLast();
void deleteFirst();
void deleteLast();
void insertMiddle();

void main()
{

    int choice = 1;
    while (choice != 0)
    {
        printf("\n\n");
        printf("Create List :1\n");
        printf("display List :2\n");
        printf("Search Element :3\n");
        printf("insert first :4\n");
        printf("insert last :5\n");
        printf("delete first :6\n");
        printf("delete last :7\n");
        printf("Insert At middle :8\n");

        printf("Enter choice :");
        scanf("%d", &choice);
        printf("\n\n");

        switch (choice)
        {
        case 1:
            create();
            break;

        case 2:
            display();
            break;

        case 3:
            search();
            break;

        case 4:
            insertFirst();
            break;

        case 5:
            insertLast();
            break;

        case 6:
            deleteFirst();
            break;

        case 7:
            deleteLast();
            break;

        case 8:
            insertMiddle();
            break;

        default:
            printf("Enter valid choice");
            break;
        }
    }
}

void create()
{
    int n;
    printf("Enter total number of nodes :");
    scanf("%d", &n);

    int data;
    struct node *newnode, *temp;

    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Unable to allocate memory");
    }
    else
    {
        printf("Enter data for node 1 :");
        scanf("%d", &data);

        head->data = data;
        head->next = NULL;

        temp = head;

        for (int i = 2; i <= n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));

            if (newnode == NULL)
            {
                printf("Unable to allocate memory");
            }
            else
            {
                printf("Enter data for node %d :", i);
                scanf("%d", &data);

                newnode->data = data;
                newnode->next = NULL;

                temp->next = newnode;
                temp = temp->next;
            }
        }
    }
}

void display()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is Empty.");
    }
    else
    {

        temp = head;

        while (temp != NULL)
        {
            printf("Data : %d\n", temp->data);

            temp = temp->next;
        }
    }
}

void search()
{
    int key, index = 0;
    struct node *curNode;

    printf("Enter key to search :");
    scanf("%d", &key);

    curNode = head;

    while (curNode != NULL && curNode->data != key)
    {
        index++;
        curNode = curNode->next;
    }

    if (curNode != NULL)
    {
        printf("Element found at position : %d", index + 1);
    }
    else
    {
        printf("Element not found");
    }
}

void insertFirst()
{
    int data;
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter data to insert  :");
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = head;

        head = newnode;
    }
}

void insertLast()
{
    struct node *newnode, *temp;
    int data;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter data to insert :");
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;

            if (temp == NULL)
            {
                break;
            }
        }
        if (temp != NULL)
        {
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
}

void deleteFirst()
{

    struct node *remove;

    if (head == NULL)
    {
        printf("The list is empty.");
    }

    remove = head;

    head = head->next;

    free(remove);
}

void deleteLast()
{
    struct node *remove, *last;

    if (head == NULL)
    {
        printf("The list is empty.");
    }
    else
    {
        remove = head;
        last = head;

        while (remove->next != NULL)
        {
            last = remove;
            remove = remove->next;
        }

        if (remove == head)
        {
            head = NULL;
        }
        else
        {
            last->next = NULL;
        }
    }
}

void insertMiddle()
{
    int position, data;
    printf("Enter position to insert data :");
    scanf("%d", &position);

    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        printf("Enter data to insert at given position : ");
        scanf("%d" , &data);

        newnode->data = data ;
        newnode->next = NULL ;

        temp = head ;

        for(int i = 2 ; i < position ; i++){
            temp = temp->next ;
            if(temp == NULL){
                break ;
            }
        }

    if(temp != NULL){
        newnode->next = temp->next ;
        temp->next = newnode ;

        printf("Data inserted successfully at given position.\n\n");
    }
        
    }
}