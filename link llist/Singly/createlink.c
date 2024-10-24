
#include<stdio.h>
#include<stdlib.h>
int main(){


struct node
{
    int data;
    struct node *next; 
};
struct node *head,*middle,*last;

head=malloc(sizeof(struct node));
middle=malloc(sizeof(struct node));
last=malloc(sizeof(struct node));
printf("Enter the data of head node: ");
scanf("%d",&head->data);

printf("Enter the data of middle node: ");
scanf("%d",&middle->data);

printf("Enter the data of last node: ");
scanf("%d",&last->data);

head->next=middle;
middle->next=last;
last->next=NULL;

struct node *temp=head;

while (temp!=NULL)
{
    printf("Data=%d\n",temp->data);
    temp= temp->next;
}
return 0;

}