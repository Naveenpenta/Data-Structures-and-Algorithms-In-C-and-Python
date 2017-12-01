//queue using stack while taking two stacks
#include<stdio.h>
#include<stdlib.h>
struct stack
{
 int a[100],top,max;
};


enque(struct stack *s1)
{int ele;
  if(s1->top==s1->max-1)
	printf("que is full\n");
  else
   {
	printf("enter NUM\n");
	scanf("%d",&ele);
	s1->top++;
	s1->a[s1->top]=ele;
   }
}
deque(struct stack *s1,struct stack *s2)
{
	if(s1->top==-1)
		printf("the que is empty\n");
	else
	{	
	  while(s1->top!=-1)
		{
			s2->top++;
			s2->a[s2->top]=s1->a[s1->top];
			s1->top--;
		}
	  printf("%d is deleted\n",s2->a[s2->top]);
		s2->top--;
	 while(s2->top!=-1)
		{
			s1->top++;
			s1->a[s1->top]=s2->a[s2->top];
			s2->top--;
		}
	}
}
display(struct stack *s1)
{int i;
 if(s1->top==-1)
	printf("the que is empty\n");
  else
  {printf("the elements are \n");
	for(i=0;i<=s1->top;i++)
	printf("%d\t",s1->a[i]);
  }printf("\n");	
}
int main()
{
 int choice;
 struct stack *s1;
 struct stack *s2;
 s1=(struct stack *)malloc(sizeof(struct stack));
  s2=(struct stack *)malloc(sizeof(struct stack));
  s1->top=-1;
  s1->max=100;
  s2->top=-1;
  s2->max=100;

  	do
	{
		printf("Enter your option\n1.Enque\n2.Dq\n3.Display\n4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enque(s1);
					break;
			case 2:
				deque(s1,s2);
					break;
			case 3:			
				display(s1);
					break;
			case 4:
				printf("completed\n");
					break;
			default:
				printf("invalid option\n");
		}
	}while(choice!=4);
}

