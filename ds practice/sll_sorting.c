#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*link;
};

struct node* create1(struct node* ptr)
{
    struct node* head1 = malloc(sizeof(struct node));
    head1->data=45;
    head1->link=NULL;
    struct node *curr=malloc(sizeof(struct node));
    curr->data=10;
    curr->link=NULL;
    head1->link=curr;
    curr=malloc(sizeof(struct node));
    curr->data=27;
    curr->link=NULL;
    head1->link->link=curr;
    curr=malloc(sizeof(struct node));
    curr->data=5;
    curr->link=NULL;
    head1->link->link->link=curr;
    return head1;
}

struct node* sorting(struct node *head1)
{
    struct node *temp=NULL;
    struct node *cpt=NULL;
    struct node *ptr=head1;
    while(ptr->link!=NULL)
    {
        cpt=ptr->link;
        while(cpt!=NULL)
        {
            if(ptr->data>cpt->data)
            {
                temp=ptr->data;
                ptr->data=cpt->data;
                cpt->data=temp;
            }
            cpt=cpt->link;
        }
        ptr=ptr->link;
    }
    return head1;
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

int main()
{
    struct node* head1,*head2;
    head1=create1(head1);
    head2=NULL;

    printf("BEFORE SORTING:\n");
    print(head1);

    printf("AFTER SORTING:");
    head2=sorting(head1);
    print(head2);
    return 0; 
}