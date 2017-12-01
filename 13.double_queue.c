//implement double queue
#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int a[100];
	int r1,r2,f1,f2;
};
int main()
{
	int max=100,choice;
	struct queue *q;
	q=(struct queue *)malloc(sizeof(struct queue));
	q->r1=-1;
	q->f1=-1;
	q->r2=max-1;
	q->f2=max-1;	
	do
		{
		printf("1.enqueue 2.dequeue  3.display  4.exit\n");
		scanf("%d",&choice);
		switch(choice)
			{
				case 1:enqueue(q);
						break;
				case 2:dequeue(q);
						break;
				case 3:display(q);
						break;
				case 4:exit(0);
						break;
				default:printf("invalid choice\n");
			}
		}
		while(choice!=4);
}
enqueue(struct queue *q)
{
	int ele,op;
	printf("enter element to insert=");
	scanf("%d",&ele);
	if(q->r1==q->r2)
		{
			printf("queue is full\n");
		}
	else
		{
			printf("1.start  2.end\n");
			scanf("%d",&op);
			if(op==1)
				{
					q->r1++;
					q->a[q->r1]=ele;
				}
			if(op==2)
				{
					q->r2--;
					q->a[q->r2]=ele;
				}
		}
}
dequeue(struct queue *q)
{
	int op;
	if(q->r1==q->f1&&q->r2==q->f2)
		{
			printf("queue is empty\n");
		}
	else
		{
			printf("1.start  2.end\n");
			scanf("%d",&op);
			if(op==1)
				{
					if(q->f1==q->r1)
						{
							printf("starting side is empty\n");
						}
					else
						{
							q->f1++;
							return q->a[q->f1];
						}
				}
			if(op==2)
				{
					if(q->r2==q->f2)
						{
							printf("ending is side is empty\n");
						}
					else
						{
							q->f2--;
							return q->a[q->f2];
						}
				}	
		}
}
display(struct queue *q)
{
	int i;
	if(q->r1==q->f1&&q->r2==q->f2)
		{
			printf("queue is empty\n");
		}
	else
		{
		printf("elements are:\n");
		for(i=q->f1+1;i<=q->r1;i++)
			{
				printf("%d ",q->a[i]);
			}
		for(i=q->f2-1;i>=q->r2;i--)
			{
				printf("%d ",q->a[i]);
			}
		printf("\n");
		}
}	
