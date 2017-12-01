//linked list implementation count the repetion numbers 
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
				case 4:count();
						break;
				case 5:printf("exit\n");
						break;
				default:printf("invalid option\n");
						main();
			
			}
	}while(opt!=5);
}
insertion()
{		int num,optt,n,p,i;
		printf("enter number to insert\n");
		scanf("%d",&num);
		if(head==NULL)
			{
				head=(struct node*)malloc(sizeof(struct node));
				head->e=num;
				head->next=NULL;
			}
		else
			{	temp=(struct node*)malloc(sizeof(struct node));
				temp->e=num;
				printf("1 start 2 middle 3 last\n");
				scanf("%d",&optt);
				if(optt==1)
					{
						temp->next=head;
						head=temp;
					
					
					}
				if(optt==2)
					{
						temp1=head;
						printf("enter position\n");
						scanf("%d",&n);
						for(i=1;i<n;i++)
						{	
							temp1=temp1->next;
						}		
						temp->next=temp1->next;
						temp1->next=temp;
						
					}
				if(optt==3)
					{
						temp1=head;
						while(temp1->next!=NULL)
							temp1=temp1->next;
						temp1->next=temp;
						temp->next=NULL;
					}
			
			}

}
deletion()
{
	int p,n,i,numm,j;
	if(head==NULL)
		{
				printf("list is empty\n");	
		}
	else
		{
			printf("1 start 2 middle 3 ens 4 find\n");
			scanf("%d",&p);
			if(p==1)
				{	printf("%d is deleted\n",head->e);
					head=head->next;
					
				}
			if(p==2)
				{	temp1=head;
					printf("enter position \n");
					scanf("%d",&n);
					for(i=1;i<n;i++)
						{temp2=temp1;
						temp1=temp1->next;}
					temp2->next=temp1->next;
				
				}
			if(p==3)
				{
					temp1=head;
					while(temp1->next!=NULL)
						{	
							temp2=temp1;
							temp1=temp1->next;
						}
						temp2->next=NULL;				
				}
			if(p==4)
				{	if(head==NULL)
						printf("empty\n");
					else
					{		
						printf("enter number to find\n");
						scanf("%d",&numm);
						temp1=head;
						while(temp1!=NULL)
						{
							if(temp1->e==numm)
								{
									j=1;
									break;
								}
							else
								{
									temp1=temp1->next;
								}
						}
						if(j==1)
							{	
								if(head->next==NULL)
									{
										head=head->next;
									}
								else
									{ 	temp2=head;
										while(temp2->next!=temp1)
										{	
											temp2=temp->next;
										}
										temp2->next=temp1->next;
									}
							
							}
						else
							{
								printf("number is not found\n");
							}
					} 
				}
		}
}
display()
{	temp1=head;
	if(head==NULL)
		printf(";list is empty\n");
	else
	{
		while(temp1->next!=NULL)
			{
			  printf("%d ",temp1->e);
			  temp1=temp1->next;
			}
	}printf("%d ",temp1->e);

}
count()
{
	
	int i=0;
	if(head==NULL)
		printf("list is empty\n");
	else
	{	temp1=head;
		while(temp1->next!=NULL)
			{
				
				temp1=temp1->next;
				i++;
			}	
		printf("the count number is %d",i+1);
	}
}


