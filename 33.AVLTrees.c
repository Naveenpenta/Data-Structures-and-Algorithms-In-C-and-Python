//avl trees
#include<stdio.h>
#include<stdlib.h>
struct node 
{
        struct node * llink;
        struct node * rlink;
        int data;
}*root;
int min=0;
main()
{
        int n=1,a;
        while(n!=0)
        {
        printf("Press\n\t1-INSERT_NODE\n\t2-DELETE_NODE\n\t3-PRI_ORDER\n\t4-POST_ORDER\n\t5-IN_ORDER\n\t6-EXIT\n");
        scanf("%d",&a);
        switch(a)
        {
                case 1:{
                                struct node * q=(struct node*)malloc(sizeof(struct node));
                                printf("Enter the data:");
                                scanf("%d",&q->data);
                                insert(root,q);
                                //printf("hai");
                               checkInvalid(root);
                                break;
                              }
                case 2:{
                                int x;
                                printf("enter which element do you want to delete:");
                                scanf("%d",&x);
                                search(x); 
                                } 
                                break;             
                case 3:
                                priOrder(root);
                                break;
               case 4:
                                postOrder(root);
                                break;
               case 5:
                                inOrder(root);
                                break;              
             case 6:
                                n=0;
                                break;
              default:
                                printf("You have entered invalid option");                                                         
                
        }   
        }
}
checkInvalid(struct node *t)
{
	if(!t)
		return;
	else
	{
		min=0;
		int min1=findOrder(root->llink,0);
		min=0;
		int min2=findOrder(root->rlink,0);
		//printf("hai");
		if(min1-min2==2||min1-min2==-2)
		{
			rotate(root,min1-min2);
			checkInvalid(root);	
		}	
		else 
		{
		checkInvalid(t->llink);
		checkInvalid(t->rlink);
		}
		//printf("hai");		
	}	
}
findOrder(struct node *root,int count)
{
	
	if(!root){
		if(min<count)
			min=count;
		}
	else{
		findOrder(root->llink,count+1);
		findOrder(root->rlink,count+1);	
		}
}
struct node * findParent(struct node *root,struct node *q)
{
	if(!root)
	 	return NULL;
	if(root->llink==q)
		return root;
	else
		findParent(root->llink,q);	
	if(root->rlink==q)
		return root;
	else
		findParent(root->rlink,q);		
		 	
}
rotate(struct node *q,int count)
{
	struct node *parent=NULL;
	parent=findParent(root,q);
	//printf("okkk");
	if(!parent&&count>0)
		root=root->llink;
	else if(!parent&&count<0)
		root=root->rlink;	
	else
	{
	if(q->data<parent->data)
	{
		if(count>0)
		parent->llink=q->llink;
		else
		parent->llink=q->rlink;
	}	
	else
	{
		if(count>0)
			parent->rlink=q->llink;
		else
			parent->rlink=q->rlink;	
	}	
	}
	if(count>0)
	{
	struct node *temp=q->llink;
	q->llink=q->llink->rlink;
	//printf("%d\n",q->llink->data);	
	temp->rlink=q;
	}
	else
	{
	struct node *temp=q->rlink;
	q->rlink=q->rlink->llink;
	//printf("%d  %d",0,q->data);	
	temp->llink=q;	
	}	
}
delete(struct node *p,struct node *q)
{
              if(q->llink==NULL&&q->rlink==NULL)
                {
                      if(root!=q)
                      {
                    if(q->data<p->data)
                        p->llink=NULL;
                    else
                        p->rlink=NULL;
                        } 
                        else
                        root=NULL;                 
                } 
                else if(q->llink==NULL)
                {
                      if(q!=root)
                      {  
                    if(q->data<p->data)
                        p->llink=q->rlink;
                    else
                        p->rlink=q->rlink;   
                        }
                        else
                        {
                                root=root->rlink;
                        }                         
                } 
                 else if(q->rlink==NULL)
                {
                        if(root!=q)
                        {
                    if(q->data<p->data)
                        p->llink=q->llink;
                    else
                        p->rlink=q->llink;   
                        }else
                        {
                                root=root->llink;
                        }                         
                } 
                else
                {
                  struct node *temp=q->rlink,*temp2=q;
                  if(temp->llink==NULL)
                  {
                  temp->llink=q->llink;
                  if(root!=q)
                  {
                    if(temp->data<p->data)          
                        p->llink=temp;
                    else
                        p->rlink=temp;   
                     } 
                     else
                     {
                        root=root->rlink;
                     }      
                  }
                  else
                  {
                  while(temp->llink!=NULL)
                  {
                        temp2=temp;
                        temp=temp->llink;
                  }
                  temp2->llink=NULL;
                  q->data=temp->data;
                   }    
                }      
}
search(int ele)
{
         if(root==NULL)
        {
                printf("No NODES are present.");
        }
        else if(root->data==ele)
        {
                    printf(" %d is present.",ele); 
                   delete(root,root);
        }
        else{
        struct node *temp2=NULL;
        struct node *temp=root;    
        while(1)
        {
        if(temp->data==ele)
        {
                printf(" %d is present.",ele);
                delete(temp2,temp);
                break;
        }
        else if(temp->data>ele)
        {
                if(temp->llink!=NULL)
                        {
                        temp2=temp;
                        temp=temp->llink;
                       // printf("hiihiiiiiii");
                        }
                 else{
                       printf("%d is not present.",ele);  
                        break; 
                        }                                    
        }
        else 
        {
                   if(temp->rlink!=NULL)
                   {
                        temp2=temp;
                        temp=temp->rlink;
                    }    
                 else{
                       printf("%d is not present.",ele);  
                        break;
                        }                       
        }
        }
        }
}
insert(struct node * t,struct node *q)
{
       // printf("hai");
        if(t==NULL)
        {
                root=q;
                   // printf("hai");
        }
        else if(q->data>=t->data)
        {
                if(t->rlink==NULL)
                        t->rlink=q;
                else
                        insert(t->rlink,q);      
                          
        }
        else
        {
                if(t->llink==NULL)
                        t->llink=q;
                 else
                        insert(t->llink,q);       
        }
        
}
postOrder(struct node * root)
{
        if(root==NULL)
        {
                return;
        }
        postOrder(root->llink);
        postOrder(root->rlink);
        printf("%d\t",root->data);        
}
priOrder(struct node * root)
{
        if(root==NULL)
        {
                return;
                }
        printf("%d\t",root->data) ;       
        priOrder(root->llink);
        priOrder(root->rlink);
      
}
 
inOrder(struct node * root)
{
        if(root==NULL)
                {
                return ; 
                }
        inOrder(root->llink);
        printf("%d\t",root->data);     
        inOrder(root->rlink);   
}
