#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL; // Initialize the head pointer as NULL

// Function to create a new node with the given data
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a node at the beginning of the linked list
void insertFirst(int value) {
    struct node *newNode = createNode(value);
    if (newNode) {
        newNode->next = head;
        head = newNode;
    }
}

// Function to insert a node at the end of the linked list
void insertLast(int value) {
    struct node *newNode = createNode(value);
    if (newNode) {
        if (head == NULL) {
            head = newNode;
        } else {
            struct node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Function to delete the first node of the linked list
void deleteFirst() {
    if (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to delete the last node of the linked list
void deleteLast() {
    if (head != NULL) {
        if (head->next == NULL) {
            free(head);
            head = NULL;
        } else {
            struct node *temp = head;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            free(temp->next);
            temp->next = NULL;
        }
    }
}

// Function to find an element in the linked list
struct node *find(int value) {
    struct node *current = head;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    int choice, value;
    struct node *foundNode;

    do {
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Delete from the beginning\n");
        printf("4. Delete from the end\n");
        printf("5. Create linked list\n");
        printf("6. Find an element\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert at the beginning: ");
                scanf("%d", &value);
                insertFirst(value);
                break;

            case 2:
                printf("Enter a value to insert at the end: ");
                scanf("%d", &value);
                insertLast(value);
                break;

            case 3:
                deleteFirst();
                break;

            case 4:
                deleteLast();
                break;

            case 5:
                // Create a linked list with sample values
                head = NULL; // Reset the head pointer
                insertLast(10);
                insertLast(20);
                insertLast(30);
                insertLast(40);
                insertLast(50);
                break;

            case 6:
                printf("Enter a value to find: ");
                scanf("%d", &value);
                foundNode = find(value);
                if (foundNode) {
                    printf("Element found in the list: Data=%d\n", foundNode->data);
                } else {
                    printf("Element not found in the list.\n");
                }
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    // Free memory for the entire linked list before exiting
    while (head != NULL) {
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
