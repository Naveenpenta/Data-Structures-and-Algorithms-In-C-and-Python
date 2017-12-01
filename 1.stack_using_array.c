//stack using array
#include<stdio.h>
void push(int a[],int *top,int max);
int pop(int a[],int *top,int max);
int main()
{    int a[100],top=-1,max;
       max=100;
       int op,poped;
   do{
      printf("enter a your option\n1.PUSH\n2.POP\n3.EXIT\n");
      scanf("%d",&op);
      switch(op)
       		{
         		case 1: 
						push(a,&top,max);
						break;
    			case 2:
						poped=pop(a,&top,max);
                       if(poped==1000)
                           {}
							
						else
							{	
                             	printf("poped element is %d\n",poped);
                             	
							}
						break;
				case 3:
						printf("exited\n");
						break;
				default:
						printf("invalid option choose only from the above option \n");
			}

	 }while(op!=3);
}
void push(int a[],int *top,int max)
          {
                        if(*top+1==max)
								{
								 	printf("stack is full\n");
								}
                    	 else 
								{ (*top)++;
                                  printf("enter element to push\n");
                                  scanf("%d",&a[*top]);
                                  printf("element is pushed into the stack\n");
								}				
			}
int pop(int a[],int *top,int max)
    {  if(*top==-1)
       	{
         	printf("stack is empty\n");
            return 1000;
		}
       else
		{
         return a[(*top)--];
		}
	}

