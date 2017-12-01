//binary search tree
#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	int e;
	struct tnode *left,*right;
}*root,*temp,*temp1,*new;
struct que
{
	struct tnode*a[100];
	int r,f;
};
enque(struct que *q,struct tnode *tt)
{
	q->r++;
	q->a[q->r]=tt;
}
struct tnode *deque(struct que *q)
{
	q->f++;
	return q->a[q->f];
}
int isempty(struct que *q)
{
	if(q->r==q->f)
		return 1;
	else
		return 0;
}

main()
{
		int n;
	root=NULL;
	do
	{
		printf("1 insertion 2 display 3 find 4max min 5 exit\n");
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
{int num,num1;
	
	
	if(root==NULL)
	{
	printf("enter number to insert bst\n");
	scanf("%d",&num);
	root=(struct tnode *)malloc(sizeof(struct tnode));
	root->e=num;
	root->left=NULL;
	root->right=NULL;
	}
	else
	{	printf("enter number to insert bst\n");
	    scanf("%d",&num1);
		new=(struct tnode *)malloc(sizeof(struct tnode));
		new->left=NULL;
		new->right=NULL;
		new->e=num1;
		
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->r=-1;
		q->f=-1;
		enque(q,root);
		while(!isempty(q))
		{	temp=(struct tnode *)malloc(sizeof(struct tnode));
			temp=deque(q);
			if(temp->e>new->e)
			{
				if(temp->left!=NULL)
				{
					enque(q,temp->left);
				}
				else
				{
					
					temp->left=new;
					printf("left inserted\n");
					break;	
					

				}
			}
			else
				{
					if(temp->right!=NULL)
						enque(q,temp->right);
					else
					{
						
						temp->right=new;
						printf("right inserted");
						break;
					}		
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
{
printf("enter number to find\n");
	int numme;
	scanf("%d",&numme);
	
	struct que *q;
	q=(struct que *)malloc(sizeof(struct que));
	q->f=-1;
	q->r=-1;
	enque(q,root);
	while(!isempty(q))
	{
		temp=(struct tnode *)malloc(sizeof(struct tnode));
		temp=deque(q);
		if(temp->e==numme)
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
	if(temp->e==numme)
		printf("numer found\n");
	else
		printf("not found\n");

}
maxmin()
{	
	
	struct que*q;
	q=(struct que *)malloc(sizeof(struct que));
	q->f=-1;
	q->r=-1;
	enque(q,root);
	while(!isempty(q))
	{
		temp=(struct tnode *)malloc(sizeof(struct tnode));
		temp=deque(q);
		printf("%d\t",temp->e);
		if(temp->left!=NULL)
		{
			enque(q,temp->left);
		}
		if(temp->right!=NULL)
		{
			enque(q,temp->right);
		}
	}


}

