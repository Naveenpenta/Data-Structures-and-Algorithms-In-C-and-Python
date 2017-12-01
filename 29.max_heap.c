//max heap
#include<stdio.h>
struct tnode
{
	struct tnode *left;
	struct tnode *right;
	int e;

}*root,*temp,*new,*temp1;
struct que
{
	struct tnode *a[100];
	int r,f;
};
enque(struct que *q,struct tnode *ff)
{
	q->r++;
	q->a[q->r]=ff;
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
int findparent(struct tnode *ff)
{
	if(ff==NULL)
	{
	}
	else if(ff->left==temp||ff->right==temp)
		{
			temp=ff;
		}
	else
		{
			findparent(ff->left);
			findparent(ff->right);
		}
}
main()
{	int n;
	root=NULL;
	do
	{
		printf("1 insert 2 delete 3 display");
		scanf("%d",&n);
	switch(n)
	{
		case 1:
 	          		insertion();
 	         	break;
			case 2:
				deletion();
	            	break;
			case 3:display(root);
					break;
			
	         case 4:
	               		printf("ur exited from stack\n");
						
    	          	break;       
 		   	default :
  	     	        printf("invalid option\n");
 	      	        main();
	}
	}while(n!=4);
	
}
insertion()
{
	int num,t;
	printf("enter number to insert in max heap\n");
	scanf("%d",&num);
	new=(struct tnode*)malloc(sizeof(struct tnode));
	new->e=num;
	new->left=NULL;
	new->right=NULL;
	if(root==NULL)
	{
		root=new;
	}
	else
	{
		struct que *q;
		q=(struct que *)malloc(sizeof(struct que));
		q->f=-1;
		q->r=-1;
		enque(q,root);
		while(!isempty(q))
		{
			temp=(struct tnode *)malloc(sizeof(struct tnode));
			temp=deque(q);
			if(temp->left!=NULL)
				enque(q,temp->left);
			else
			{
				temp->left=new;
				printf("left side\n");
				break;
			}
			if(temp->right=NULL)
				{
					enque(q,temp->right);
				}
			else
			{
					temp->right=new;
					printf("right side\n");
					break;

			}
		
		}
		while(new->e>temp->e)
		{
			t=new->e;
			new->e=temp->e;
			temp->e=t;
			new=temp;
			if(temp!=root)
				findparent(root);	
		} 
		
	}

}
deletion()
{
int n,k,t;
	temp=root;
	temp1=root;
	while(temp->right!=NULL || temp->left!=NULL)
	{
		if(temp->left==NULL)
		{
			temp1=temp;
			temp=temp->right;
			t=temp1->e;
			temp1->e=temp->e;
			temp->e=t;
	
		}
		else if(temp->right==NULL)
		{
			temp1=temp;
			temp=temp->left;
			t=temp1->e;
			temp1->e=temp->e;
			temp->e=t;			
		
		}
		else
		{
			if(temp->left->e>temp->right->e)
			{
				temp1=temp;
				temp=temp->left;
				t=temp1->e;
				temp1->e=temp->e;
				temp->e=t;
			
			}
			else
			{
				temp1=temp;
				temp=temp->right;
				t=temp1->e;
				temp1->e=temp->e;
				temp->e=t;	
	
			}

		}

	}
	if(temp1==temp)
	{
		printf("%d ",temp->e);
		root=NULL;
	}
	else if(temp1->left==temp)
		{
			printf("%d\n",temp->e);
			temp1->left=NULL;
			
		}
	else
		{
			printf("%d\n",temp->e);
			temp1->right=NULL;
		}	


}
display(struct tnode *root)
{
	if(root==NULL)
	{
	}
	else
	{
	display(root->left);
	printf("%d ",root->e);
	display(root->right);
	}
	

}
