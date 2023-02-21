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

struct node* addatEnd(struct node* tail,int data)
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


struct node* delFirst(struct node* tail)
{
    if(tail==NULL)
    {
        return tail;
    }
    struct node* temp = tail->next;
    if(temp==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
	tail->next=temp->next;
    temp->next->prev=tail;
	free(temp);
	return tail;
}

struct node* delLast(struct node* tail)
{
    struct node* temp;
    if(tail==NULL)
    {
        return tail;
    }
    if(temp==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    temp=tail->prev;
    temp->next=tail->next;
    temp->next->prev=temp;
    free(tail);
    tail=temp;
    return tail;
}

struct node* delAtPos(struct node* tail,int pos)
{
    struct node* temp =tail->next;
    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }        
    struct node* temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    if(temp==tail)
        tail=temp2;    
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
    tail=addatEnd(tail,34);
    tail=addatEnd(tail,67);
    tail=addatEnd(tail,95);
    printf("\n before deletion:");
    print(tail);

    tail=delFirst(tail);
    tail=delLast(tail);
    tail=delAtPos(tail,2);
    printf("\n after deletion:");
    print(tail);
    return 0;
}