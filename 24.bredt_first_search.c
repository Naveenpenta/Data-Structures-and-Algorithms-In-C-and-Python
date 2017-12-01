//bredth first search
#include<stdio.h>
#include<stdlib.h>
int **a;
int *queue,front=-1,rear=-1;
breadthfirstSearch(int s,int visited[],int n){
	//printf("Entered\n");
	visited[s]=1;
	enqueue(s);
	while(!isEmpty()){
		int k=dequeue();
		int i;
		for(i=0;i<n;i++){
			if(a[k][i]==1&&visited[i]==-1){
				visited[i]=1;
				enqueue(i);
				}
		}/*visited[s]=1;
		enqueue(s);
		while(!isEmpty()){
		int k=dequeue();
		for(int i=0;i<n;i++){
			if(a[k][i]==1&&visited[i]==-1){
				visited[i]=1;
				enqueue(i);
			}

		}*/

	}
}
int isEmpty(){
	if(front==-1&&rear==-1)
			return 1;
	return 0;
}
 enqueue(int s){
	if(front==-1&&rear==-1){
		front=0;
		rear=0;
		}
	else{
		rear++;
		}
	queue[rear]=s;
	 printf(" %d  ",queue[rear]);
}

int dequeue(){
	int t;
	if(front==rear){
		t=queue[front];
		front=-1;
		rear=-1;
		}
	else{
		t=queue[front];
		front++;
	}
	return t;
}
main(){
	printf("Enter how many vertices you have: \t");
	int n;
	scanf("%d",&n);
	a=(int **)malloc(n*sizeof(int *));
	int i=0;
	queue=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		a[i]=(int *)malloc(n*sizeof(int));
		}
		printf("Enter adjacency matrix:\n");
	int j;
	int visited[n];
	for(i=0;i<n;i++){
		visited[i]=-1;
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
				}
			}
	printf("Enter from which node you want start visiting:\n");
	int start;
	scanf("%d",&start);
	breadthfirstSearch(start,visited,n);
	
	for(i=0;i<n;i++){
		if(visited[i]!=1){	
			//printf("%d\t",visited[i]);
			printf("Graph is not connected\n");return;
			}
		}
	printf("Graph is connected\n");
	}
