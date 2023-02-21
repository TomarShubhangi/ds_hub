#include<stdio.h>
#include<stdlib.h>
int c,n,d,ele,q[100],r=-1,f=-1;
int size()
{
    return((n-f+r)%n);
}
int isempty()
{
    return(f==r);
}
int front()
{
    if(isempty())
    {
        printf("queue is empty");
    }
    else
    {
        return(q[f]);
    }
}
void dqueue()
{
    if(isempty())
    {
        printf("queue is empty");
    }
    else
    {
        f=(f+1)%n;
    }
}
void enqueue()
{
    if(r==n-1)
    {
        printf("queue is full");
    }
    else
    {
    	if(f==-1)
    	{
		    f=0;
		    printf("Enter the element to be inputed: ");
            scanf("%d",&ele);
		    r=r+1;
		    q[r]=ele;
		}
    }
void show()
{
    if(isempty())
    {
        printf("queue is empty");
    }
    else
    {   
        int i;
        for(i=f;i<=n;i++)
        {
            printf("\n q[%d]=%d \n",i,q[i]);
        } 
    }
}

int main()
{ 
    printf("size of queue: ");
    scanf("%d",&n);
    printf("\nWhat funtion do you want to do\n 1.Size\n 2.Front\n 3.Dqueue\n 4.Enqueue\n 5.Show\n 6.Exit\n ") ;
    do
	{
	    printf("enter the choice: ") 
		scanf("%d",&c);
        switch(c)
		{
            case 1:
                d=size();
                printf("size=%d",d);
                break;
            case 2:
                printf("front element=%d",front());
                break;
            case 3:
                dqueue();
                break;
            case 4:
                enqueue();
                break;
            case 5:
                show();
                break;
            case 6:
                break;
            default:
                printf("invalid funtion");
        }
    }
    while(c!=6);
    return 0;
}