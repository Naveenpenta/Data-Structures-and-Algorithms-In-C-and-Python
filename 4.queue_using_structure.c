//que using structure..

#include<stdio.h>
struct que{
	int r;
	int f;
	int que[5];
};
int main()
{
	struct que q;
	q.r=-1;
	q.f=-1;
	int max=5,opt;
	do{
			printf("1 enque 2 deque 3 display 4 exit\n");
			scanf("%d",&opt);
			switch(opt)
			{
				case 1:enque(&q,max);
						break;
				case 2:deque(&q,max);
						break;
				case 3:display(&q);
						break;
				case 4:printf("exit\n");
						break;
				case 5:printf("invalid option\n");
						main();


			}
	}while(opt!=4);
}
enque(struct que *q,int max)
{
	int num;
	if(q->r==max-1)
		printf("que is full\n");
	else
	{
		printf("enter number to enque\n");
		scanf("%d",&num);
		q->r=q->r+1;
		q->que[q->r]=num;
		printf("%d is enqued\n",q->que[q->r]);

	}

}
deque(struct que *q,int max)
{
    if(q->f==q->r)
        {
        	printf("que is empty\n");
        	
        }
	else
		{   q->f=q->f+1;
			printf("%d is dequed",q->que[q->f]);
					
		
		}

}
display(struct que *q)
{		int i;
		if(q->f==q->r)
				printf("que is empty\n");
		else
		{
			for(i=q->f+1;i<=q->r;i++)
				printf("%d ",q->que[i]);
		}

}
