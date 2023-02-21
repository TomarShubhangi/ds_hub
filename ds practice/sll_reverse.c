#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*link;
};

struct node* addAtEnd(struct node* ptr,int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->data=data;
	temp->link=NULL;
	ptr->link=temp;
	return temp;
}

void print(struct node*head)
{
    struct node* ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    printf("\n");
}

struct node* reverse(struct node* head)
{
	struct node *prev=NULL;
    struct node *next=NULL;
    while(head!=NULL)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}


int main()
{
    struct node* head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    struct node *ptr=head;
    ptr=addAtEnd(ptr,98);
    ptr=addAtEnd(ptr,67);
    ptr=addAtEnd(ptr,3);
    
    printf("Before reversing the list:\n");
    print(head);
    head=reverse(head);
    printf("After reversing the list:\n");
    print(head);
    return 0; 
}