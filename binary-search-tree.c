#include<stdio.h>
#include<stdlib.h>
typedef enum {false,true} boolean;
typedef struct node* pointer;
typedef struct node
{
	int data;
	pointer rchild;
	pointer lchild;
}node;
void insert(pointer* root,int d)
{
	if(*root==NULL)
	{
		*root=(pointer)malloc(sizeof(node));
		(*root)->data=d;
		(*root)->lchild=NULL;
		(*root)->rchild=NULL;
	}
	else if(d>(*root)->data)
	{
		insert(&(*root)->rchild,d);
	}
	else
	{
		insert(&((*root)->lchild),d);
	}
}
boolean search(pointer root,int d)
{
	if(root==NULL)
		return false;
	if(root->data==d)
		return true;
	else if((d>(root)->data))
		return search(root->rchild,d);
	else
		return search(root->lchild,d);
}
void inorder(pointer root)
{
	if(!root)
	{
		return;
	}
	else
	{
		inorder((root)->lchild);
		printf("%d",(root)->data);
		inorder((root)->rchild);
	}
}
int main()
{
	pointer root=NULL;
	int ch,d;
	while(1)
	{
		printf("Enter 1-insert 2-display 3-search 4-exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter the element to insert\n");
			       scanf("%d",&d);
			       insert(&root,d);
			       break;
			case 2:inorder(root);
			       break;
			case 3:printf("Enter the data to search for\n");
			       scanf("%d",&d);
			       if(search(root,d))
				       printf("element found");
			       else
				       printf("Element not found");
			       break;
			case 4:exit(0);
		}
	}
}
					 
