#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};

struct node *addToEmpty(int data)    
{
    struct node *temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node* addAtEnd(struct node* tail,int data)
{
	struct node* newP = malloc(sizeof(struct node));
	newP->data=data;
	newP->next=NULL;

    newP->next=tail->next;
    tail->next=newP;
	tail=tail->next;
	return tail;
}

struct node* createlist(struct node*tail)
{
    int i,n, data;
    printf("Enter no of nodes:");
    scanf("%d",&n);

    if(n==0)
    {
        return tail;
    }
    printf("Enter the elements:");
    scanf("%d",&data);
    tail=addToEmpty(data);

    for(i=1;i<n;i++)
    {
        printf("Enter the elements %d :",i+1);
        scanf("%d",&data);
        tail=addAtEnd(tail,data);
    }
    return tail;
}

struct node* delLast(struct node* tail)
{
    if(tail==NULL)
    {
        return tail;
    }
    struct node* temp =tail->next;
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
}

struct node* delAtPos(struct node* tail,int pos)
{
    if(tail==NULL)
    {
        return tail;
    }
    struct node* temp =tail->next;
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
    while(pos>2)
    {
        temp=temp->next;
        pos--;
    }        
    struct node* temp2=temp->next;
    temp->next=temp2->next;
    if(temp2==tail)
        tail=temp;
    free(temp2);
    temp2=NULL;    
    return tail;
}

struct node* delFirst(struct node* tail)
{
    if(tail==NULL)
    {
        return tail;
    }
    if(tail->next==tail)
    {
        free(tail);
        tail=NULL;
        return tail;
    }
	struct node* temp = tail->next;
	tail->next=temp->next;
	free(temp);
    temp=NULL;
	return tail;
}

void print(struct node*tail)
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
    struct node *tail;
    tail=createlist(tail);
    printf("\n before deletion:");
    print(tail);
    
    tail=delFirst(tail);
    tail=delLast(tail);
    tail=delAtPos(tail,2);
    printf("\n after deletion:");
    print(tail);
    return 0;
}