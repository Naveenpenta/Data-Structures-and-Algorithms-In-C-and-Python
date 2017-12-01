//min heap
#include<stdio.h>
struct tnode
{
	int e;
	struct tnode *left,*right;

}*root,*new,*temp,*temp1;
struct que 
{
	struct tnode *a[100];
	int r,f;

};
enque(struct que *q,struct tnode *hh)
{
	q->r++;
	q->a[q->r]=hh;
}
struct tnode *deque(struct que *q)
{
	q->f++;
	return q->a[q->f];

}
int isempty(struct que *q)
{
	if(q->f==q->r)
		return 1;
	else
		return 0;

}
int findparent(struct tnode *ff)
{
	if(ff==NULL)
	{
	}
	else if(ff->left==temp || ff->right==temp)
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
{
		int n;
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
	printf("enter number to insert in minheap\n");
	scanf("%d",&num);
	new=(struct tnode *)malloc(sizeof(struct tnode));
	new->e=num;
	new->left=NULL;
	new->left=NULL;
	if(root==NULL)
	{
		root=new;
	}
	else
	{
		struct que *q;
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
						printf("left\n");
						break;
			
					}
				if(temp->right!=NULL)
					enque(q,temp->right);
				else
					{	
						temp->right=new;			
					printf("right\n");
					break;
					}
	
			
		}
		while(new->e<temp->e)
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
display(struct tnode *root)
{
	if(root==NULL)
	{
	}
	else
	{
		printf("%d ",root->e);
		display(root->left);
		display(root->right);
	}
	
}
int swap(struct tnode *temp,struct tnode *temp1)
{
	int t;
	t=temp->e;
	temp->e=temp1->e;
	temp1->e=t;
}
deletion()
{
	int n,t;
	temp=root;
	temp1=root;
	while(temp->left!=NULL || temp->right!=NULL)
	{
			if(temp->left==NULL)
			{
				temp1=temp;
				temp=temp->right;
				swap(temp,temp1);
			}
			else if(temp->right==NULL)
			{
				temp1=temp;
				temp=temp->left;
				swap(temp,temp1);
			}
			else
			{
				if(temp->left->e>temp->right->e)
				{
					temp1=temp;
					temp=temp->right;
					swap(temp,temp1);
				}
				else
				{
					temp1=temp;
					temp=temp->left;
					swap(temp,temp1);
				}
	
			}
	}
	if(temp1==temp)
	{
		printf("%d\n",temp->e);
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
