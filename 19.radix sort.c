//radic sort
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
insert(int a,int var,struct node *b[])
{
	if(b[var]==NULL)
	{
		b[var]=(struct node *)malloc(sizeof(struct node));
		b[var]->data=a;
		b[var]->next=NULL;
	}
	else
	{
		struct node *temp=b[var];
		struct node *temp1;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp1=(struct node *)malloc(sizeof(struct node));
		temp1->data=a;
		temp1->next=NULL;
		temp->next=temp1;
	}
}
int *copy(int a[],struct node *b[],int n)
{
		
	int i,j=0;
	for(i=0;i<n;i++)
	{
		if(b[i]!=NULL){
		struct node *temp=b[i];
		while(temp->next!=NULL)
		{
			a[j++]=temp->data;
			temp=temp->next;
		}
		a[j++]=temp->data;
	}
	}
}
int main()
{
	int i,n,k,j,q,w,var,l,a[10],max,c=0;
	struct node *b[10];
	printf("enter how many numbers you want insert\n");
	scanf("%d",&n);
	printf("enter elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[0];
	for(i=1;i<n;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	while(max!=0)
	{
		c++;
		k=max%10;
		max=max/10;
	}
	for(i=0;i<n;i++)
	{
		b[i]=NULL;
	}
	q=10;
	w=1;
	for(l=0;l<c;l++)
	{
		for(j=0;j<n;j++)
		{
			var=a[j]%q;
			var=var/w;
			insert(a[j],var,b);
		}
		copy(a,b,n);
			for(i=0;i<n;i++)
				{
						b[i]=NULL;
				}
		q=q*10;
		w=w*10;
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
