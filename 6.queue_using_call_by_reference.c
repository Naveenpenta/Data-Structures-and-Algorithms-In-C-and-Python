//queue using call by reference
#include<stdio.h>

int main()
{ int f=-1,r=-1,a[100],opt,max=100;
	
	do
	{
		printf("1 enque 2 deque 3 display 4 exit\n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:enque(max,&r,a);
					break;
			case 2:dequeue(&f,max,r,a);
					break;
			case 3:display(r,f,a);
					break;
			case 4:printf("you entered to exit\n");
					break;
			default:printf("invalid option\n");
					main();
	
		}
	
		
	}while(opt!=4);

}
enque(int max,int *r,int a[])
{	int num;
	if(*r==max-1)
		{printf("stack is overflow");}
	else
	{
		printf("enter number to enque\n");
		scanf("%d",&num);
		(*r)++;
		a[*r]=num;
		printf("%d is enqued\n",a[*r]);
		
	}

}

dequeue(int *f,int max,int r,int a[])
{
		if(*f==r)
			printf("list is empty\n");
		else
		{
			*f=*f+1;
			printf("%d is dequeued",a[*f]);
		}

}
display(int r,int f,int a[])
{	int i;
	if(f==r)
	printf("que is empty\n");
	else
	{
		for(i=f+1;i<=r;i++)
		{
			printf("%d ",a[i]);
		}

	}

}
