//double lined list
#include<stdio.h>
#include<stdlib.h>
struct node{
int e;
struct node *pre;
struct node *next;
}*header,*temp,*temp1;

main()
{
  int choice;
  printf("this is doubly linked list\n");
  header=NULL;
  do{
	
	printf("enter your choice\n");
	scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
					break;
			case 2:
				delete();

					break;
			case 3:
				traverse();
					break;
			case 4:
				printf("exit\n");
					break;
			default:
				printf("invalid\n");
		}
	}while(choice!=4);

}


insert()
{
  int ele,po,p,i;

	printf("enter element\n");
	scanf("%d",&ele);
		if(header==NULL)
		{
			header=(struct node *)malloc(sizeof(struct node));		 

			header->e=ele;
			header->pre=NULL;
			header->next=NULL;
		  printf("%d is entered\n",header->e);
		}
		 else
		{
			temp=(struct node *)malloc(sizeof(struct node));
			temp->e=ele;
		
			printf("enter place  \n 1.strat\n 2.middle\n 3.end\n ");
			scanf("%d",&p);
		
			if(p==1)
			  {
				temp->next=header;
				header->pre=temp;
				temp->pre=NULL;
				header=temp;
				}
			if(p==2)
			{
				printf("enter position \n");
				scanf("%d",&po);
				temp1=(struct node *)malloc(sizeof(struct node));
				temp1=header;
				
				for(i=1;i<po;i++)
					{
						temp1=temp1->next;
						}
					temp->next=temp1->next;
					temp1->next->pre=temp;
					temp1->next=temp;
					temp->pre=temp1;
				}
			if(p==3)
			{
				temp1=header;

				while(temp1->next!=NULL)
					{
						temp1=temp1->next;
						}
					temp1->next=temp;
					temp->next=NULL;
					temp->pre=temp1;
				}
		}

}
delete()
{
  int p,i,po;
  if(header==NULL)
	{
		printf("the list is empty\n");

		}

      else
	{
		printf("enter place\n 1.start\n 2.middle\n 3.end\n");
		scanf("%d",&p);
		
		if(p==1)
		{
			header=header->next;
			//header->pre=NULL;
			}
		if(p==2)
		{
			printf("enter your position\n");
			scanf("%d",&po);
		
			temp1=header;
		
			for(i=0;i<po;i++)
				{
					temp1=temp1->next;
					}
				temp1->pre->next=temp1->next;
				temp1->next->pre=temp1->pre;
			}
		if(p==3)
		{
			temp1=header;

			while(temp1->next!=NULL)
				{
					temp1=temp1->next;
					}
				temp1->pre->next=NULL;
			}

	}
   
}


traverse()
{
  if(header==NULL)
	printf("the list is empty\n");
  else
   {
	printf("the elements are\n");
	
	temp1=header;
	
	while(temp1->next!=NULL)
		{
			printf("%d \t",temp1->e);
			temp1=temp1->next;
			}
	       printf("%d \t",temp1->e);
	}
}
