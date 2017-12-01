//bubble sort
#include<stdio.h>
int main()
{	int a[20],n,i,j,temp;
	printf("enter numbers\n");
	scanf("%d",&n);
	printf("enter %d the number\n",n);
	for(i=0;i<n;i++)
	{scanf("%d",&a[i]);
	}//bubble sort
	for(i=n-2;i>=0;i--)
	{
	   for(j=0;j<=i;j++)
	   {
		if(a[j]>a[j+1])
		{
		  temp=a[j];
		  a[j]=a[j+1];
		  a[j+1]=temp;
		}
	}
	}
	printf("result\n");	
	for(i=0;i<n;i++)
	{printf("%d ",a[i]);
}printf("\n");
}
