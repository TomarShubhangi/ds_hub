#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*next;
};

struct node *circularsingly(int data)      //ADD TO EMPTY LIST
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

struct node* addAtPos(struct node* tail,int data,int pos)
{
	struct node* p=tail->next;
    struct node* newP = malloc(sizeof(struct node));
	newP->data=data;
	newP->next=NULL;
    while(pos<1)
    {
        p=p->next;
        pos--;
    }
    newP->next=p->next;
    p->next=newP;

    if(p==tail)
    {
        tail=tail->next;
    }
    return tail;
}

struct node* addAtBeg(struct node* tail,int data)
{
	struct node* newP = malloc(sizeof(struct node));
	newP->data=data;
	newP->next=tail->next;
	tail->next=newP;
	return tail;
}

void print(struct node*tail)
{
    struct node* ptr=tail->next;
    do 
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    while(ptr!=tail->next);
}

void countEle(struct node* tail)
{
    struct node* temp=tail->next;
    int count=0;
    while(temp!=tail)
    {
        temp=temp->next;
        count++;
    }
    count++;
    printf("\n there are %d no of elements in list:",count);
}

int searchEle(struct node* tail,int ele)
{
    struct node *temp;
    int index=0;
    if(tail==NULL)
    {
        return-2;
    }
    temp=tail->next;
    do{
        if(temp->data==ele)
            return index;
        temp=temp->next;
        index++;    
    }while(temp!=tail->next);
    return-1;
}

int main()
{
    struct node *tail;
    tail=circularsingly(34);
    tail=addAtBeg(tail,67);
    tail=addAtEnd(tail,3);
    tail=addAtPos(tail,10,2);
    print(tail);

    countEle(tail);
    int ele;
    printf("\n Enter the ele to be searched:");
    scanf("%d",&ele);
    int index=searchEle(tail,ele);
    if(index==-1)
    {
        printf("Element not found");
    }
    else if(index==-2)
    {
        printf("list is empty");
    }
    else
    {
        printf("element %d is at index %d",ele,index);
    }
    return 0;
}