//stack with linked list
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
	printf("1 push 2 pop 3 display 4 exit\n");
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
{		int num,optt,n,p,i;
		printf("enter number to push\n");
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
				    
						temp->next=head;
						head=temp;
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
		
		    printf("%d is poped\n",head->e);
					head=head->next;
					
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
