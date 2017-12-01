//depth first search
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[100][100],visit[100],i,j,n;
	printf("enter no.of elements");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				{
					scanf("%d",&a[i][j]);
				}
		}
	for(i=0;i<n;i++)
		{
			visit[i]=0;
		}
		i=0;
	dfs(a,visit,i,n);
}
dfs(int a[100][100],int visit[100],int i,int n)
{
	int j;
	printf("%d ",i);
	visit[i]=1;
	for(j=0;j<n;j++)
		{
			if(a[i][j]==1&&visit[j]==0)
				dfs(a,visit,j,n);
		}
}
