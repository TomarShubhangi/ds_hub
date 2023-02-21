#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
	int data;
	struct node *next;
};

struct node *addToEmpty(int data)
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    temp->prev=temp;
    return temp;
}

struct node* addAtBeg(struct node* tail,int data)
{
	struct node* newP = addToEmpty(data);
    if(tail==NULL)
    {
        return newP;
    }
    else
    {
        struct node*temp=tail->next;
        newP->prev=tail;
        newP->next=temp;
        temp->prev=newP;
        tail->next=newP;
	    return tail;
    }
}

struct node* addAtEnd(struct node* tail,int data)
{
	struct node* newP = addToEmpty(data);
    if(tail==NULL)
    {
        return newP;
    }
    else
    {
        struct node*temp=tail->next;
        newP->next=temp;
        newP->prev=tail;
        tail->next=newP;
        temp->prev=newP;
        tail=newP;
	    return tail;
    }    
}

struct node* addAtPos(struct node* tail,int data,int pos)
{
	struct node* newP = addToEmpty(data);
    if(tail==NULL)
    {
        return newP;
    }
    struct node* temp=tail->next;
    while(pos<1)
    {
        temp=temp->next;
        pos--;
    }
    newP->next=temp;
    newP->next=temp->next;
    temp->next->prev=newP;
    temp->next=newP;

    if(temp==tail)
    {
        tail=tail->next;
    }
    return tail;
}    


void print(struct node* tail)
{
    if(tail==NULL)
    {
        printf("NO node in list");
    }
    else
    {
        struct node* ptr=tail->next;
        do 
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        while(ptr!=tail->next);
    }
}

int main()
{
    struct node *tail=NULL;
    tail=addToEmpty(45);
    tail=addAtBeg(tail,34);
    tail=addAtPos(tail,56,2);
    print(tail);
    return 0;
}