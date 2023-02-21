#include<stdio.h>
#include<conio.h>
int a[100],i,choice,n,top,x;
void push()
{
    if(i<100)
    {
    	for(i=0;i<n;i++)
        {
        	printf("\n push values into stack:\n",a[i]);
		    scanf("%d",&a[i]);
		    push(a[i]);
     	}
    }
    else
    {
        printf("stack is full");
    }
}
void pop()
{
    if(top<0)
    {
        printf("stack underflow");
    }
    else
    {
		top--;
		for(i=0;i<=top;i++)
        {
            printf("a[%d]=%d\n",i,a[i]);
        }
	}
}
void display()
{
	for(i=0;i<=top;i++)
    {
        printf("a[%d]=%d\n",i,a[i]);
    }
}
int size()
{
    return top+1;
}
int is_empty()
{
    return(top<0);
}
int peek()
{
    return top;
}
int main()
{
    int i,n;
    top=-1;
    printf("\n Enter size of stack: ");
	scanf("%d",&n);
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
