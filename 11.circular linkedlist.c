//circular linked list;;

#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
	int e;
	struct node *next;
}*head,*temp,*temp1,*temp2;
int main()
{	head=NULL;
	int opt;
	do{
	printf("1 insert 2 delete 3 display 4 exit\n");
	scanf("%d",&opt);
		switch(opt)
			{
				case 1:insertion();
						break;
				case 2:deletion();
						break;
				case 3:display();
						break;
				case 4:printf("exit\n");
						break;
				default:printf("invalid option\n");
						main();
			
			}
	}while(opt!=4);
}
insertion()
{
	int num,i,k,j,opt;
	printf("enter number to insert\n");
	scanf("%d",&num);
	if(head==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->e=num;
		head->next=head;
	}
	else
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->e=num;
		printf("1 start 2 middele 3 end\n");
		scanf("%d",&i);
		if(i==1)
			{
				temp1=head;
				while(temp1->next!=head)
						temp1=temp1->next;
				temp1->next=temp;
				temp->next=head;
				head=temp;
			}
		if(i==2)
			{
				temp1=head;
				printf(" enter posion\n");
				scanf("%d",&j);
				for(k=1;k<j;k++)
					temp1=temp1->next;
				temp->next=temp1->next;
				temp1->next=temp;			
	
			}
		if(i==3)
			{
				temp1=head;
				while(temp1->next!=head)
						temp1=temp1->next;
					temp1->next=temp;
					temp->next=head;
			}
			
	}


}
display()
{	temp1=head;
	if(head==NULL)
		
			printf("list is empty");
	else
		{
			while(temp1->next!=head)
				{
					printf("%d ",temp1->e);
					temp1=temp1->next;
				}printf("%d ",temp1->e);
				
		
		}
		
}
deletion()
{		int j,p,t,l;
	if(head==NULL)
		printf("list is empty\n");
	else if(head->next==head)
		{
				printf("%d is deleted\n",head->e);
				head=NULL;
		}
	else
		{
			printf("1 start 2 middle 3 end\n");
			scanf("%d",&p);
			if(p==1)
				{
					temp1=head;
					while(temp1->next!=head)
							{
							temp1=temp1->next;}
						temp1->next=head->next;
						head=head->next;
				}
			if(p==2)
				{
					temp1=head;
					printf("enter position\n");
					scanf("%d",&l);
					for(t=1;t<l;t++)
						{
							temp2=temp1;
							temp1=temp1->next;	
						}
							temp2->next=temp1->next;
				}
			if(p==3)
				{
					temp1=head;
					while(temp1->next!=head)
							{
								temp2=temp1;
								temp1=temp1->next;
							}
						temp2->next=head;
				}
		}
}

