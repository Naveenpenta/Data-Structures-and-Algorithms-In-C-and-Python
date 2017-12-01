//chaining
#include<stdio.h>
#include<stdlib.h>
void insert();
void find();
void delete();
void display();
struct node
{
  int e;
  struct node * next;
}*a[10];

int main()
{
  int ch,i;
	for(i=0;i<10;i++)  
	{
		a[i]=NULL;
	}
	printf("This is chaining in hashing that means we use linked list\n");

	do
	{
		printf("1 insert\n2 find\n3 delete\n4 display\n5 exit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				insert();
					break;
			case 2:
				find();
					break;
			case 3:
				delete();
					break;
			case 4:
				display();
					break;
			case 5:
				printf("quited\n");
					break;
			default:
				printf("Invalid option\n");

		}
	}while(ch!=5);
}

void insert()
{
  int ele,k;

	printf("Enter Number to insert\n");
	scanf("%d",&ele);
	
	k=ele%10;
	
	if(a[k]==NULL)
	{
		a[k]=(struct node *)malloc(sizeof(struct node));
		
		a[k]->e=ele;
		a[k]->next=NULL;
		printf("inserted\n");
	}
	else
	{
		struct node *temp=a[k];
	
		while(temp->next!=NULL)
		    temp=temp->next;
		struct node *temp1=(struct node *)malloc(sizeof(struct node));
			temp1->e=ele;
			temp1->next=NULL;

			temp->next=temp1;

			printf("inserted %d\n",temp1->e);
	}
}

void find()
{
  int ele,k;
	printf("Enter element to find\n");
	scanf("%d",&ele);
	k=ele%10;
	if(a[k]==NULL)
	{
		printf("There is no element \n");
	}
	else
	{
		struct node *tmp=a[k];
		while(tmp->next!=NULL)
		{
			if(tmp->e==ele)
			{
				break;
			}
			else
			{
				tmp=tmp->next;
			}
		}
			
		if(tmp->e==ele)
			printf("NUMber found\n");
		else
			printf("NO there is no number like that\n");
	}
}
void delete()
{
 int ele,k;
  
	printf("Enter number to delete\n");
	scanf("%d",&ele);
	
	k=ele%10;

	if(a[k]==NULL)
	{
		printf("THERE IS NO ELEMENT LIKE THAT\n");
	}
	else
	{
		struct node *tmp=a[k];
		if(tmp->next==NULL)
		{
			if(tmp->e==ele)
			{  printf("%d is deleted\n",tmp->e);
		   	   a[k]=NULL;
			}
			else
				printf("not found\n");
		}
		else
		{	if(a[k]->e==ele)
			{
				a[k]=a[k]->next;
			}
			else{while(tmp->next!=NULL)
			{
				if(tmp->e==ele)
				{
					break;
				}
				else
				{
					tmp=tmp->next;
				}
			}

			if(tmp->e==ele)
			{
				struct node *tmp1=a[k];

				while(tmp1->next!=tmp)
				{
					tmp1=tmp1->next;
				}

				tmp1->next=tmp->next;
			}}
			
		}	
	}
}
void display()
{
   int k;
for(k=0;k<10;k++)
  { if(a[k]!=NULL)
   {	struct node *temp1=a[k];
		while(temp1->next!=NULL)
		{
			printf("%d\t",temp1->e);
				temp1=temp1->next;
		}
			printf("%d\n",temp1->e);
			
    }
  }
}
