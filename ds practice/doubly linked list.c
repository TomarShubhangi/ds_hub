#include<stdio.h>
#include<stdlib.h>

struct node{
	struct node*prev;
	int data;
	struct node*next;
};

struct node* addToEmpty(struct node* head,int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->prev =NULL;
	temp->data=data;
	temp->next=NULL;
	head=temp;
	return head;
}

struct node* addAtBeg(struct node* head,int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->prev =NULL;
	temp->data=data;
	temp->next=NULL;
	temp->next=head;
	head->prev=temp;
	head=temp;
	return head;
}

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

struct node* addAfterPos(struct node* head,int data,int position)
{
	struct node* newP=NULL;
	struct node* temp=head;
	struct node* temp2=NULL;
	newP=addToEmpty(newP,data);
	while(position!=1)
	{
		temp=temp->next;
		position--;
	}
	if(temp->next==NULL)
	{
		temp->next=newP;
		newP->prev=temp;
	}
	else
	{
        temp2=temp->next;
		temp->next=newP;
		temp2->prev=newP;
		newP->next=temp2;
		newP->prev=temp;
	}
	return head;
}

struct node* addBeforePos(struct node* head,int data,int position)
{
	struct node* newP=NULL;
	struct node* temp=head;
	struct node* temp2=NULL;
	newP=addToEmpty(newP,data);
	int pos=position;
	while(pos>2)
	{
		temp=temp->next;
		pos--;
	}
	if(position==1)
	{
		head=addAtBeg(head,data);
	}
	else
	{
        temp2=temp->next;
		temp->next=newP;
		temp2->prev=newP;
		newP->next=temp2;
		newP->prev=temp;
	}
	return head;
}

int main()
{
	struct node* head=NULL;
	struct node* ptr;
	int position=2;
	head=addToEmpty(head,45);
	head=addAtBeg(head,34);
	head=addAtEnd(head,9);
	head=addAfterPos(head,25,position);
	head=addBeforePos(head,10,position);

	ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->next;
	}
	return 0; 
}
