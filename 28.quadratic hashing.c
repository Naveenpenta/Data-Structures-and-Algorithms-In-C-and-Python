//quadratic hashing
#include<stdio.h>
void insert();
void find();
void delete();
void display();

int main()
{
   int ch,a[100],i,n,size;
		printf("This is hashing \n");

		printf("enter the sizeof array\n");
		scanf("%d",&n);
		size=n;
		for(i=0;i<n;i++)
		{
			a[i]=-1;
		}
	
	
	do
	{
		printf("Enter Your Choice\n1.insert\n2.find\n3.delete\n4.display\n5.exit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				insert(a,size);
					break;
			case 2:
				find(a,size);
					break;
			case 3:
				delete(a,size);
					break;
			case 4:
				display(a,size);
					break;
			case 5:
				printf("The program exited\n");
					break;
			default:
				printf("The choice is invalid\n");
		}
	}while(ch!=5);
}

void insert(int a[],int size)
{
  int ele,i,loc;

	printf("Enter element to insert\n");
	scanf("%d",&ele);
	
	for(i=0;i<size;i++)
	{
		loc=(ele%size+i*i)%size;
		
		if(a[loc]==-1)
		{
		   a[loc]=ele;
			break;
		}
	}
}
void find(int a[],int size)
{
  int ele,loc,i,s;

	printf("Enter Number to find\n");
	scanf("%d",&ele);
		
	for(i=0;i<size;i++)
	{
		loc=(ele%size+i*i)%size;

		if(a[loc]==ele)
		{
			s=1;
			break;
		}
	}

	if(s==1)
	{
			printf("The NUMber find\n");
	}
	else
	{
			printf("The NUMber notfind\n");
	}

}

void delete(int a[],int size)
{
  int ele,loc,i;

	printf("Enter NUMber to delete \n");
	scanf("%d",&ele);

	for(i=0;i<size;i++)
	{
		loc=(ele%size+i*i)%size;
		
		if(a[loc]==ele)
		{
			a[loc]=-1;
				break;
		}
	}
}
void display(int a[],int size)
{
  int i;
	printf("the elements are\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
}

