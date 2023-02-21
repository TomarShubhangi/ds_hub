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

struct node* addAtBeg(struct node* head,int data)
{
	struct node* ptr = malloc(sizeof(struct node));
	ptr->data=data;
	ptr->link=NULL;
	ptr->link=head;
    head=ptr;
	return head;
}

void addAtPos(struct node* head,int data,int pos)
{
	struct node* ptr=head;
    struct node* ptr2 = malloc(sizeof(struct node));
	ptr2->data=data;
	ptr2->link=NULL;
	pos--;
    while(pos!=1)
    {
        ptr=ptr->link;
        pos--;
    }
    ptr2->link=ptr->link;
    ptr->link=ptr2;
}

int main()
{
    struct node* head = malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;
    struct node *ptr=head;
    ptr=addAtEnd(ptr,98);
    head=addAtBeg(head,3);
    int data=67,pos=3;
    addAtPos(head,data,pos);
    
    ptr=head;
    while(ptr!=NULL)
    {
	    printf("%d ",ptr->data);
	    ptr=ptr->link;
    }
    return 0; 
}