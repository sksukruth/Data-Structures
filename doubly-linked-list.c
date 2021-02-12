#include<stdio.h>
#include<stdlib.h>
typedef struct node* pointer;
typedef struct node
{
	int data;
	pointer llink;
	pointer rlink;
}node;
void insert(pointer head,int d)
{
	pointer temp;
	temp=(pointer)malloc(sizeof(node));
	temp->data=d;
	temp->llink=head;
	temp->rlink=head->rlink;
	head->rlink->llink=temp;
	head->rlink=temp;
	head=temp;
}
int delete(pointer head,int d)
{
	if(head==NULL)
	{
		printf("Empty\n");
		return 0;
	}
	head=head->rlink;
	if((head->data)==-1)
	{
		printf("Cannot delete header node\n");
		return d;
	}
	while((head)->data!=-1)
	{
		if(d==head->data)
		{
			printf("Deleted:%d\n",d);
			if(head->rlink)
				head->llink->rlink=head->rlink;
			if(head->llink)
				head->rlink->llink=head->llink;
			return d;
		}
		head=head->rlink;
	}
	printf("Element not found\n");
	return 0;
}
void displayr(pointer head)
{
	head=head->rlink;
	if(head==NULL)
		printf("Empty\n");
	while((head->rlink)->data!=-1)
	{
		printf("%d\t",head->data);
		head=head->rlink;
	}
	if(head->data!=-1)
		printf("%d\n",head->data);
	else
		printf("Emmpty");
}
void displayf(pointer head)
{
        head=head->llink;
        if(head==NULL)
                printf("Empty\n");
        while((head->llink)->data!=-1)
        {
                printf("%d\t",head->data);
                head=head->llink;
        }
       printf("%d\n",head->data);
}
void main()
{
	int ch,d;
	pointer first;
	first=(pointer)malloc(sizeof(node));
	first->data=-1;
	first->llink=first;
	first->rlink=first;
	while(1)
	{
		printf("Enter 1-insert 2-delete 3-display forward 4-display backward 5-exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to insert\n");
			       scanf("%d",&d);
			       insert(first,d);
			       break;
			case 2:printf("Enter the element to delete\n");
			       scanf("%d",&d);
			      	delete(first,d);
				break;
			case 3:displayf(first);
			       break;
			case 4:displayr(first);
			       break;
			case 5:exit(0);
		}
	}
}









































