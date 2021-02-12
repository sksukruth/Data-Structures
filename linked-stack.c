#include<stdio.h>
#include<stdlib.h>
typedef struct stack* pointer;
typedef struct stack
{
	int data;
	pointer link;
}stack;
pointer top[5];
void push(pointer *top,int d)
{
	pointer temp;
	temp=(pointer)malloc(sizeof(stack));
	temp->data=d;
	temp->link=*top;
	*top=temp;
}
int pop(pointer *top)
{
	if(*top==NULL)
	{
		
		return -1;

		}
	int m;
	pointer temp;
	temp=(pointer)malloc(sizeof(stack));
	temp=*top;
	m=temp->data;
	*top=temp->link;
	free(temp);
	return m;
}
void display(pointer top)
{
	for(;top;top=top->link)
	{
		printf("%d",top->data);
	}
}

int main()
{
	int ch,d,i,m;
	while(1)
	{
		printf("Enter 1-push 2-pop 3-display 4-exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the stack number to insert data\n");
				scanf("%d",&i);
				printf("Enter the data to push\n");
				scanf("%d",&d);
				push(&top[i],d);
				break;
			case 2: printf("Enter the stack number to pop from\n");
				scanf("%d",&i);
				m=pop(&top[i]);
				if(m==-1)
				{
					printf("Stack is empty\n");
				}
				else
					printf("The element deleted is %d\n",m);
				break;
			case 3: printf("Enter the stack number to be displayed\n");
				scanf("%d",&i);
				display(top[i]);
				break;
			case 4: exit(0);
		}
	}
	return 0;
}

