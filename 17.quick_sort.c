//quicksort
#include<stdio.h>
main()
{
	printf("enter how many numbers you want to insert\n");
	int n;
	scanf("%d",&n);
	printf("enter %d numbers",n);
	int i,a[100];	
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
			
	}
	int start=0;
	int end=n-1;
	printf("your enter numbes are\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}printf("\n");
	quicksort(a,start,end);
	printf("after quick sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}	
}
quicksort(int a[],int start ,int end)
{	

	int pivot,i,j;
	if(start >= end)
		{
		}
	else if(end-start==1)
	{
		if (a[start]>a[end])
			swap(a,start,end);
	}
	else
	{	
		pivot=a[start];
		i=start+1;
		j=end;
		while(i<j)
		{
				while(a[i]<pivot)
						i++;
				while(a[j]>pivot)
						j--;
				if(i<j)
					swap(a,i,j);
				else
					swap(a,j,start);
		
		}
		quicksort(a,start,j-1);
		quicksort(a,j+1,end);
	}

}
swap(int a[],int start,int end)
{
	int temp;
	temp=a[end];
	a[end]=a[start];
	a[start]=temp;

}
