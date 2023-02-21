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

struct node* delFirst(struct node* head)
{
	if(head==NULL)
    {
        printf("List is empty");
    }
    else
    {
        struct node *temp=head;
        head=head->link;
        free(temp);
        temp=NULL; 
    }
	return head;
}

void delLast(struct node* head)
{
	if(head==NULL)
    {
        printf("List is empty");
    }
    else if(head->link==NULL)
    {
        free(head);
        head=NULL;
    }
    else
    {
        struct node *temp=head;
        while(temp->link->link!=NULL)
        {
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;
    }
}

void delPos(struct node* head,int pos)
{
    struct node *curr=head;
    struct node *prev=head;
	if(head==NULL)
    {
        printf("List is empty");
    }
    else if(pos==1)
    {
        head=curr->link;
        free(curr);
        curr=NULL;
    }
    else
    {
        while(pos!=1)
        {
            prev=curr;
            curr=curr->link;
            pos--;
        }
        prev->link=curr->link;
        free(curr);
        curr=NULL;
    }
}

struct node* delList(struct node* head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        temp=temp->link;
        free(head);
        head=temp;
    }
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
    ptr=addAtEnd(ptr,10);
    head=delFirst(head);
    delLast(head);
    int pos=2;
    delPos(head,pos);
    head=delList(head);
    if(head==NULL)
    {
        printf("List is empty");
    }
    return 0;

    ptr=head;
    while(ptr!=NULL)
    {
	    printf("%d ",ptr->data);
	    ptr=ptr->link;
    }
    return 0; 
}