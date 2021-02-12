#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct 
{
	int key;
}element;
element heap[MAXSIZE];
void insert(element item,int *n)
{
	int i;
	if((*n)==MAXSIZE-1)
	{
		printf("HEAPFULL\n");
		return;
	}
	i=++(*n);
	while(i!=1&&item.key>heap[i/2].key)
	{
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i]=item;
}
element delete(int* n)
{
	int parent,child;
	element item,temp;
	if(*n==0)
	{
		printf("HeapEmpty\n");
		item.key=-1;
		return item;
	}
	item=heap[1];
	temp=heap[(*n)--];
	while(child<=*n)
	{
		if(child<*n&&(heap[child].key<heap[child+1].key))
			child++;
		if(temp.key>=heap[child].key)
			break;
		heap[parent]=heap[child];
		parent=child;
		child=child*2;
	}
	heap[parent]=temp;
	return item;
}
void display(int n)
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d\t",heap[i].key);
}
int main()
{
	int n=0,choice;
	element item;
	while(1)
	{
		printf("enter 1-insert 2-delete 3-display 4-exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter the element\n");
				scanf("%d",&item.key);
				insert(item,&n);
				break;
			case 2: item=delete(&n);
				printf("item delelted is %d\t",item.key);
				break;
			case 3: display(n);
				break;
			case 4: exit(0);
		}
	}
}


