#include<stdio.h>
#include<stdlib.h>
struct node{
		int e;
		struct node *prev,*next;
		
}*head,*temp,*temp1,*temp2;
int main()
{	head=NULL;
	int opt;
	do{
		printf("1 insert 2 delete 3 display 4 exit: ");
		scanf("%d",&opt);
		switch(opt)
			{
				case 1:insert();
						break;
				case 2:delete();
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
insert()
{
		int num,pp,l,i;
		printf("enter number to insert\n");
		scanf("%d",&num);
		if(head==NULL)
			{	head=(struct node *)malloc(sizeof(struct node));
				head->e=num;
				head->prev=NULL;
				head->next=NULL;
			
			}
		else
		
		{
				temp=(struct node*)malloc(sizeof(struct node));
				temp->e=num;
				printf("1 start 2 middle 3 end\n");
				scanf("%d",&pp);			
				if(pp==1)
				{
					temp->prev=NULL;
					temp->next=head;
					head->prev=temp;
					head=temp;
				}
				if(pp==2)
				{	
					temp1=head;
					printf("enter position\n");
					scanf("%d",&l);
					for(i=1;i<l;i++)
							{	temp2=temp1;
								temp1=temp1->next;
							}
								temp1->prev=temp;
								temp->next=temp1;
								temp->prev=temp2;
								temp2->next=temp;
				
				}
				if(pp==3)
				{
					temp1=head;
					while(temp1->next!=NULL)
							temp1=temp1->next;
						temp1->next=temp;
						temp->prev=temp1;
						temp->next=NULL;
							
				}
		
		}		
	
}
delete()
{	
	int k,i,d,ppp;
	if(head==NULL)
		{
			printf("list is empty\n");
		}
	else
		{
			printf("1 start 2 middle 3 end 4 find to delete\n");
			scanf("%d",&k);
			if(k==1)
			{   printf("%d is deleted",head->e);
				head=head->next;
				
				head->prev=NULL;
			}
			if(k==2)
			{		temp1=head;
					printf("enter position\n");
					scanf("%d",&ppp);
					for(i=1;i<=ppp;i++)
						temp1=temp1->next;
					temp1->prev->next=temp1->next;
					temp1->next->prev=temp1->prev;						
				
			}
			if(k==3)
			{
				temp1=head;
				while(temp1->next!=NULL)
						{
							temp2=temp1;
							temp1=temp1->next;
						}
				temp2->next=NULL;
			
			}	
			if(k==4)
			{
					temp=head;
					temp1=head;
					printf("enter number to find and then delete\n");
					scanf("%d",&d);
					if(head->e==d)
						{
							printf("%d is deleted\n",head->e);
							head=head->next;
							head->prev=NULL;
						
						}
					else
						{
							while(temp->next!=NULL)
								{
									if(temp->e==d)
										{	printf("%d is deleted\n",temp->e);
											break;}
									else
										{
											temp=temp->next;
										}	
								}
							while(temp1->next!=temp)
									  temp1=temp1->next;
								temp1->next=temp->next;
								temp->next->prev=temp1;
									
								
						
						}
						
						
			}
			
		}



}
display()
{
	if(head==NULL)
		{
			printf("list is empty\n");
		}
	else
		{
			temp1=head;
			while(temp1->next!=NULL)
				{
					printf("%d ",temp1->e);
					temp1=temp1->next;
				
				}printf("%d ",temp1->e);
		
		}
}
