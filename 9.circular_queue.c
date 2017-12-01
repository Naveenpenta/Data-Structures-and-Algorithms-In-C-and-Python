//circular queue
#include<stdio.h>
void enque();
int deque();
int k=0,f,r,a[5],max;

int main()
{  max=5;
  int op,ele,dequed;
   f=-1;
   r=-1;
do{
	printf("enter ur option\n1.enque\n2.deque\n3.exit\n");
	scanf("%d",&op);
 switch(op)
		{
         case 1: 
				enque();
				break;
		 case 2:
                dequed=deque();
				printf("dequed element is %d\n",dequed);
  				break;
		 case 3:
				printf("exited\n");
         default:
 				printf("invalid option\n");
		}
  }while(op!=3);
}
void enque()
	{  if((f==r)&&(k==1))
			{
             printf("que is ffull\n");
			}
       else
			{  if(r+1==max)
				{ if(f!=-1)
					{    r=0;
                        printf("enter element\n");
                        scanf("%d",&a[r]);
					    printf("element is inserted into que sucessfully\n");
						 if(f==r)
  						    k=1;                       

				     }
                   else
					{printf("que is full\n");}
                  }
                  else
					{ r++;
                      
                      printf("enter element \n");
                      scanf("%d",&a[r]);
                      printf("element is inserted into que sucessfully\n");
                      
                       if(f==r)
						{
                         k=1;
						}
					} 

				}

			

	}
int deque()
		{ if((r==f)&&(k==0))
			{
			  printf("que is empty\n");
			}
           else
			{ if(f+1==max)
                { return a[f];
					f=0;
                  if(f==r)
					{
						k=0;
					}
                  
				}
              else
				{ f++;
                  if(r==f)
					{
                       k=0;
					}
                  return a[f];
				}
            
			}


		}

