// selection sort
#include<stdio.h>
main()
{
	int i,j,n,a[20],temp;
	printf("enter total no of elements\n");
	scanf("%d",&n);
	printf("enter array elements\n");
	for(i=0;i<n;i++)
	{scanf("%d",&a[i]);}
	for(i=0;i<n;i++)
	{
	  for(j=i+1;j<n;j++)
	  {
	    if(a[i]>a[j])
	    {
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
 	     }
	  }

	}
	printf("after sorting array elements are\n");
	for(i=0;i<n;i++)
	{ 
	 printf("%d ",a[i]);
	}
	printf("\n");

}
