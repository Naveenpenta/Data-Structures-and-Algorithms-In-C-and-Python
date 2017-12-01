//insortion method
#include<stdio.h>
int main()
{
	int i,j,temp,n,a[10];
	printf("enter total no of elements\n");
 	scanf("%d",&n);
	printf("enter elements in array\n");
	for(i=0;i<n;i++)
	  {
	  scanf("%d",&a[i]);
	  }
	for(i=1;i<n;i++)
	 {
	   temp=a[i];
	   j=i-1;
	
	while((temp<a[j])&&(j>=0))
	   {
	    a[j+1]=a[j];
	    j--;
	   }
	    a[j+1]=temp;
	 }
	
	printf("after sorting array elements are \n");
	for(i=0;i<n;i++)
	{ 
	  printf("%d ",a[i]);
	}	
	printf("\n");
	
	


}
