#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node*prev;
	int data;
	struct node*next;
};

struct node* addAtEnd(struct node* head,int data)
{
	struct node* temp, *tp;
	temp = malloc(sizeof(struct node));
	temp->prev =NULL;
	temp->data=data;
	temp->next=NULL;
	tp=head;
	while(tp->next!=NULL)
	{
		tp=tp->next;
	}
	tp->next=temp;
	temp->prev=tp;
	return head;
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
        head=head->next;
        free(head->prev); 
        head->prev=NULL;
    }
	return head;
}

struct node* delLast(struct node* head)
{
	struct node *temp=head;
    struct node *temp2=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    return head;
}

struct node* delPos(struct node* head,int pos)
{
    struct node *temp=head;
    struct node *temp2=NULL;
	if(pos==1)
    {
        head=delFirst(head);
        return head;
    }
    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL)
    {
        head=delLast(head);
    }
    else
    {
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        free(temp);
        temp=NULL;
    }
    return head;
}

int main()
{
    struct node* head = malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=45;
    head->next=NULL;
    struct node *ptr=head;
    ptr=addAtEnd(ptr,98);
    ptr=addAtEnd(ptr,67);
    ptr=addAtEnd(ptr,3);
    ptr=addAtEnd(ptr,10);
    head=delFirst(head);
    head=delLast(head);
    int pos=2;
    head=delPos(head,pos);

    ptr=head;
    while(ptr!=NULL)
    {
	    printf("%d ",ptr->data);
	    ptr=ptr->next;
    }
    return 0; 
}