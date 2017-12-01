//queue using array
#include<stdio.h>
 void enque(int a[100],int *r,int max);
int deque(int a[100],int *f,int r);
int main()
{
  int r=-1,f=-1,a[100],max,op,dequed;
  max=100;
do{
  printf("enter ur option\n1.enque\n2.deque\n3.exit\n");
  scanf("%d",&op);
  switch(op)
		{ case 1: 
				 enque(a,&r,max);
				 break;
		  case 2:  dequed=deque(a,&f,r);
					if(dequed==999)
					{
                      printf("que is empty\n");
					}
                  else
					{
				      
				      printf("dequed element is %d \n",dequed);
					}
				 break;
          case 3:
				 printf("extited\n");
    			 break;
          default:
				 printf("invalid option\n");

		}
     }while(op!=3);
}

void  enque(int a[],int *r,int max)
		{   if(*r+1==max)
				{
				printf("que is full\n");
				}
            else
				{ (*r)++;
					printf("enter element \n");
                    scanf("%d",&a[*r]);
					printf("element is inserted sucessfully in a que\n");
				}
		}
int deque(int a[],int *f,int r)
				{ if(*f==r)
					{ 
                     
                     return 999; 
					}
                   else 
					{
                      (*f)++;
                      return a[(*f)];

					}
				}



