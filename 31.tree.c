//tree
#include<stdio.h>
struct tnode
{
	int e;
	struct tnode* left;
	struct tnode* right;
}*root,*temp,*temp1;
struct que
{
	struct tnode* a[100];
	int f,r;
};
enque(struct que *q,struct tnode *nn)
{
	q->r++;
	q->a[q->r]=nn;

}
struct tnode* deque(struct que *q)
{
	q->f++;
	return q->a[q->f];

};
int isempty(struct que *q)
{
	if(q->f==q->r)
		return 1;
	else
		return 0;

};
main()
{
	int n;
	root=NULL;
	do
	{
		printf("1 insertion 2 display 3 find 4 exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:insertion();
					break;
			case 2:preorder(root);
					break;
			case 3:find();
					break;
			case 4:maxmin();
					break;
			case 5:printf("exit\n");
					break;
			default:printf("invalid option\n");
					main();

			


		}
	}while(n!=4);

}
insertion()
{
	int num;
	printf("enter number to insert\n");
	scanf("%d",&num);
	if(root==NULL)
	{
			root=(struct tnode *)malloc(sizeof(struct tnode));
			root->e=num;
			root->left=NULL;
			root->right=NULL;
	}
	else
	{	printf("11\n");
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->r=-1;
		q->f=-1;
		
		enque(q,root);
		while(!isempty(q))
		{
			temp=(struct tnode*)malloc(sizeof(struct tnode));
			temp=deque(q);
			if(temp->left!=NULL)
				enque(q,temp->left);
			else
				{
					temp1=(struct tnode *)malloc(sizeof(struct tnode));
					temp1->e=num;
					temp1->left=NULL;
					temp1->right=NULL;
					temp->left=temp1;
					printf("left inserted\n");
					break;
				}
			if(temp->right!=NULL)
				enque(q,temp->right);
			else
				{
					temp1=(struct tnode *)malloc(sizeof(struct tnode));
					temp1->e=num;
					temp1->left=NULL;
					temp1->right=NULL;
					temp->right=temp1;
					printf("right inserted\n");	
					break;
				}
			
				}
				
		} 
		

}
preorder(struct tnode *root)
{	
	if(root==NULL)
	{

	}
	else
	{
		printf("%d ",root->e);
		preorder(root->left);
		preorder(root->right);
	}
	
}
find()
{	int numm;
	if(root==NULL)
	{
			printf("number not find\n");
		
	}
	else
	{	printf("enter number too find\n");
		scanf("%d",&numm);
		struct que *q=(struct que*)malloc(sizeof(struct que));
		q->f=-1;
		q->r=-1;
		temp=root;
		enque(q,temp);
		while(!isempty(q))
		{
			temp=deque(q);
			if(temp->e==numm)
			{
				break;
			}
			if(temp->left!=NULL)
			{
				enque(q,temp->left);
				
			}
			if(temp->right!=NULL)
			{
				enque(q,temp->right);
			}
		}
		if(temp->e==numm)
		{
			printf("number found\n");
		}
		else
			printf("number not found\n");
	}
}
maxmin()
{	int max=-1233456539,min=123453595;
	struct que *q=(struct que*)malloc(sizeof(struct que));
		q->f=-1;
		q->r=-1;
		temp=root;
		enque(q,temp);
		while(!isempty(q))
		{
			temp=deque(q);
			if(temp->e>max)
				max=temp->e;
			if(temp->e<min)
				min=temp->e;
			if(temp->left!=NULL)
				enque(q,temp->left);	
			if(temp->right!=NULL)
				enque(q,temp->right);
			

}
	printf("%d is max %d is min",max,min);
}
