#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*link;
};

struct node* create1(struct node* ptr)
{
    struct node* head1 = malloc(sizeof(struct node));
    head1->data=0;
    head1->link=NULL;
    struct node *curr=malloc(sizeof(struct node));
    curr->data=1;
    curr->link=NULL;
    head1->link=curr;
    curr=malloc(sizeof(struct node));
    curr->data=2;
    curr->link=NULL;
    head1->link->link=curr;
    return head1;
}

struct node* create2(struct node* ptr)
{
    struct node* head2 = malloc(sizeof(struct node));
    head2->data=4;
    head2->link=NULL;
    struct node *curr=malloc(sizeof(struct node));
    curr->data=5;
    curr->link=NULL;
    head2->link=curr;
    curr=malloc(sizeof(struct node));
    curr->data=6;
    curr->link=NULL;
    head2->link->link=curr;
    return head2;
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

struct node* concat(struct node*head1,struct node*head2)
{
    struct node *ptr=NULL;
    ptr=head1;
    while(ptr->link!=NULL)
    {
        ptr=ptr->link;
    }
    ptr->link=head2;
    return head1;
}

int main()
{
    struct node* head1,*head2,*head3;
    head1=create1(head1);
    head2=create2(head2);
    head3=NULL;

    printf("BEFORE CONCAT:\n");
    print(head1);
    print(head2);

    printf("AFTER CONCAT:");
    head3=concat(head1,head2);
    print(head3);
    return 0; 
}