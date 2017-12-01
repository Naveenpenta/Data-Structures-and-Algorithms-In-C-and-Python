//mergesort
#include<stdio.h>
int main()
{
    int a[100],n,p,i,j,end,k,start;
    printf("enter how many numbers you want to insert\n");
    scanf("%d",&n);
    printf("enter your %d numbers\n",n);
    for(i=0;i<n;i++)
            scanf("%d",&a[i]);
    start=0;
    end=n-1;
    printf("the nubers are\n");
    for(j=0;j<n;j++)
            printf("%d ",a[j]);
	printf("\n");
    ms(a,start,end);
	printf("merge sort list\n");
    for(k=0;k<n;k++)
  	   printf("%d ",a[k]);
}
ms(int a[],int start,int end)
{   int mid,p;
    mid=(start+end)/2;
      if(start<end)
      {
        ms(a,start,mid);
        ms(a,mid+1,end);
        merge(a,start,mid,end);
      }
}
merge(int a[],int start,int mid,int end)
{
    int b[100],k=0,i,j;
    i=start;
    j=mid+1;
    while(i<=mid && j<=end)
	{
        if(a[i]<a[j])
            b[k++]=a[i++];
        else
            b[k++]=a[j++];
    }
  while(i<=mid)
    b[k++]=a[i++];
  while(j<=end)
  	b[k++]=a[j++];
	i=0;
   while(i<k)
    a[start++]=b[i++];
}
