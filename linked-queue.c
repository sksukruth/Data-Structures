#include<stdio.h>
#include<stdlib.h>
typedef struct queue* pointer;
typedef struct queue
{
	int data;
	pointer link;
}queue;
pointer rear[5],front[5];
void add(pointer* rear,pointer* front,int d)
{
	pointer temp;
	temp=(pointer)malloc(sizeof(queue));
	temp->data=d;
	temp->link=NULL;
	if(*front)
	{
		(*rear)->link=temp;
		
	}
	else
	{
		*front=temp;
	}
	*rear=temp;
}
int delete(pointer* front,pointer* rear)
{
	if(*front==NULL)
	{
		return -1;
	}
	int m;
	pointer temp;
	temp=(pointer)malloc(sizeof(queue));
	temp=*front;
	m=temp->data;
	*front=temp->link;
	free(temp);
	return m;

}
void display(pointer front,pointer rear)
{
	for(front;front;front=front->link)
	{
		printf("%d\t",front->data);
	}
}
int main()
{
	int ch,i,d,m;
	while(1)
	{
		printf("1-Add 2-Delete 3-Display 4-exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the queue number\n");
			       scanf("%d",&i);
			       printf("Enter the data to add\n");
			       scanf("%d",&d);
			       add(&rear[i],&front[i],d);
			       break;
			case 2:printf("Enter the queue number\n");
			       scanf("%d",&i);
			       m=delete(&front[i],&rear[i]);
			       if(m!=-1)
			       printf("Deleted=%d\n",m);
			       else
			       printf("Queue is empty\n");
			       break;
			case 3:printf("Enter queue number\n");
			       scanf("%d",&i);
			       display(front[i],rear[i]);
			       printf("\n");
			       break;
			case 4:exit(0);
		}
	}
}

