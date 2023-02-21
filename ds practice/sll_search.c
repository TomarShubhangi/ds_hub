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

void search(struct node* head,int num)
{
    struct node* ptr=NULL;
    ptr=head;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        if(ptr->data==num)
        {
            printf("FOUND AT POSITION= ");
            printf("%d",count);
        }
        ptr=ptr->link;
    }
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
    int num;
    printf("enter element to be searched: ");
    scanf("%d", &num);
    search(head,num);
    return 0; 
}