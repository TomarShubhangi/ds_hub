// Recursive C program for level order traversal of Binary Tree
#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *left, *right;
};

struct node* newNode(int data)
{
	struct node* node
		= (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

void printLevelOrder(struct node* root)
{
    int front=0,rear=0;
    struct nodequeue[Max_queue_size];
    if(!root)
        return;
    add_q(root);
    for(;;)
    {
        root=delete_q();
        if(root)
            printf("%d",root->data);
            if(root->left)
                add_q(root->left);
            if(root->right)
                add_q(root->right);
        else
            break;        
    }    
}

/* Driver program */
int main()
{
	struct node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Level Order traversal of binary tree is \n");
	printLevelOrder(root);

	return 0;
}
