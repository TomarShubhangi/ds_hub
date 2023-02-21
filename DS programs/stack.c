#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int stack[100],choice,n,top,x,i;

int main()
{
    //clrscr();
    top=-1;
    printf("\n Enter the size of STACK: ");
    scanf("%d",&n);
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.SIZE\n\t 5.IS_EMPTY\n\t 6.TOP\n\t 7.EXIT");
    do
    {
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
            	int b=size();
            	printf("The current size of STACK is %d \n",b);
            	break;
			}
			case 5:
            {
            	is_empty();
            	break;
			}
			case 6:
            {
            	peek();
            	break;
			}
            case 7:
            {
                printf("\n\t EXIT POINT ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4/5/6/7)");
            }
        }
    }
    while(choice!=7);
    return 0;
}
void push()
{
    if(top>=n-1)
    {
        printf("STACK is over flow \n");   
    }
    else
    {
        printf("Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top<=-1)
    {
        printf("Stack is under flow \n");
    }
    else
    {
        printf("The popped element is %d \n",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n STACK ELEMENTS \n");
        for(i=top; i>=0; i--)
            printf("\n%d",stack[i]);
        printf("\n Press Next Choice");
    }
    else
    {
        printf("The STACK is empty \n");
    }
   
}
int size()
{
    return top+1;
}
void is_empty()
{
    if(top==-1)
	{
		printf("The STACK is empty \n");
	}
	else
	{
		printf("The STACK is not empty \n");
	}
}
void peek()
{
	if(top==-1)
	{
		printf("The STACK is empty \n");
	}
	else
	{
		printf("The top of the STACK is %d",stack[top]);
	}
}
