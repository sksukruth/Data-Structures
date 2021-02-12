#include<stdio.h>
#include<stdlib.h>
struct node{
	int vertex;
	struct node *link;
};
typedef struct node *nodeptr;
nodeptr graph[100]={NULL};
int visited[100]={0},q[100],f=0,r=0;// Size is 100 so can store elements upto vertex value 100
void addq(int x)
{
q[r++]=x;
}
int deleteq()
{
	return q[f++];
}
int queueempty()
{
	if(f==r)
		return 1;
	return 0;
}
void bfs(int v){
	nodeptr w;
	printf("%d\t",v);
	visited[v]=1;
	addq(v);
	while(!queueempty())
	{
		v=deleteq();
		for(w=graph[v];w;w=w->link)
		{
		if(!(visited[w->vertex]))
		{
			printf("%d\t",w->vertex);
			visited[w->vertex]=1;
			addq(w->vertex);
		}
		}
	}
}
void main(){
	nodeptr temp,t;
	int k,n,i,k1;
	printf("Enter number of nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter adjacent list of node %d,-999 to stop\n",i+1);
		scanf("%d",&k);
		k1=k;
		while(k!=-999)
		{
			temp=(nodeptr)malloc(sizeof(struct node));
			temp->vertex=k;
			temp->link=NULL;
			if(!graph[k1])
				graph[k1]=temp;
			else{
				t=graph[k1];
				while(t->link)
					t=t->link;
				t->link=temp;
			}
			scanf("%d",&k);
		}

	}
	printf("Enter vertex from where bfs traversal starts\n");
	scanf("%d",&k);
	bfs(k);
	printf("\n");
}
