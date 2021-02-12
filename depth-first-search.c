#include<stdio.h>
#include<stdlib.h>
typedef struct node *ptr;
typedef struct node
{
        int vertex;
        ptr link;
}node;
int visited[20]={0};
ptr graph[20]={NULL};
void dfs(int v)
{
        ptr w;
        visited[v]=1;
        printf("%d\t",v);
        for(w=graph[v];w;w=w->link)
        {
                if(!(visited[w->vertex]))
                {
                        dfs(w->vertex);
                }
        }
}
void main()
{
        ptr t,temp;
        int n,i,k,j,k1;
        printf("Enter the number of vertices\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter the adjacency list in parent followed by child pattern enter -999 to stop\n");
                scanf("%d",&k);
                k1=k;
                while(k!=-999)
                {
                        temp=(ptr)malloc(sizeof(node));
                        temp->vertex=k;
                        temp->link=NULL;
                        if(!graph[k1])
                                graph[k1]=temp;
                        else
                        {
                                t=graph[k1];
                                while(t->link!=NULL)
                                {
                                        t=t->link;
                                }
                                t->link=temp;
                        }
                        scanf("%d",&k);
                }
        }
                printf("Enter the vertex from which u want to perform dfs\n");
                scanf("%d",&j);
                dfs(j);
}
