/*single linked list with all operation*/
#include<stdio.h>
#include<stdlib.h>
struct link
{
int e;
struct link *next;
}*header,*temp,*temp1,*temp2;
 struct link link;

element()
{
  int n,r,i,ele;
  if(header==NULL)
	printf("the list is empty\n");
  else
   {
     printf("enter number to be find\n");
     scanf("%d",&n);
	temp1=header;
      while(temp1->next!=NULL)
	{
	  if(temp1->e==n)
	  {
		i=1;
		break;
	  }
	   else
	     {
		temp1=temp1->next;
	      }
	}
	if(i==1)
	{
	  printf("the element found\n %d",temp1->e);
	  printf("enter 1.insert  2.delete\n");
	  scanf("%d",&r);
	  if(r==1)
	  {
	      printf("enter element to insert\n");
	     scanf("%d",&ele);
       	     temp=(struct link *)malloc(sizeof(struct link));
	     temp->e=ele;
	    temp->next=NULL;
	    temp->next=temp1->next;
	    temp1->next=temp;
	    printf("element isnerted\n");
	  }
	  if(r==2)
	  {
		printf("%d is deleted\n",temp1->e);
		temp2=header;
		while(temp2->next!=temp1)
		{	
			temp2=temp2->next;
		}
		  temp2->next=temp1->next;
	  }
	}
	else
	printf("the element not found\n");
	
   }
}

main()
{
 int choice;
 header=NULL;
 printf("the operation is linked list\n");

do{
   printf("enter your option\n");
   printf("1.insert  2.delete  3.display  4.element  5.exit\n");
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
			display();
				break;
		case 4:
			element();
				break;
		case 5:
			printf("exit\n");
					break;
		default:
			printf("invalid option\n");
	}
  }while(choice!=5);
 
}
   insert()
 {
  int ele,p,po,i;
  printf("enter element to insert\n");
  scanf("%d",&ele);
 
  if(header==NULL)
  {
   header=(struct link *)malloc(sizeof(struct link));
   header->e=ele;
   header->next=NULL;
   printf("%d is you entered\n",header->e);
  }
 else
   {
         temp=(struct link *)malloc(sizeof(struct link));
          temp->e=ele;
           temp->next=NULL;

      printf("1.strat  2.middle  3.end\n");
   	scanf("%d",&p);
	if(p==1)
	{
		temp->next=header;
		header=temp;
	}
	if(p==2)
	{
	   
	  temp1=header;
	  printf("enter position\n");
	  scanf("%d",&po);        
	for(i=1;i<po;i++)
		{
			temp1=temp1->next;
		}
		  temp->next=temp1->next;
		  temp1->next=temp;
	}
	if(p==3)
	{
	  
	  temp1=header;
	 while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		  temp1->next=temp;
	}
   }
 }

 delete()
{
 int p,po,i;
  if(header==NULL)
  printf("list is empty\n");
   else
   {
	printf("enter place 1.start  2.middle  3.end\n");
	scanf("%d",&p);
    	if(p==1)
	{
	  header=header->next;
	}
	if(p==2)
	{ temp1=header;
	  printf("enter position\n");
	  scanf("%d",&po);
	  
	  for(i=1;i<po;i++)
		{
			temp1=temp1->next;
		}
          temp2=header;
	  while(temp2->next!=temp1)
		{
		 temp2=temp2->next;
		}
	      temp2->next=temp1->next;
	}
	if(p==3)
	{
	 temp1=header;
	 while(temp1->next->next!=NULL)
	 	{
			temp1=temp1->next;
		}
		  temp1->next=NULL;
	}
    }
}

 display()
{
  if(header==NULL)
  printf("the list is empty\n");
  else
  {
    printf("the elements are \n");
    
    temp1=header;
	while(temp1->next!=NULL)
	{
		printf("%d \t",temp1->e);
		temp1=temp1->next;
	}
	 printf("%d \t",temp1->e);
  }
}
