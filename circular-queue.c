#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int key;
}element;
int f=0,r=0,capacity=1;
element *q;
int deleteQ();
void addQ()
{
  int j,n;
  element *newQ;
  if(f==(r+1)%capacity)
  {
        newQ=(element*)malloc(2*capacity*sizeof(element));
	for(j=0;j<capacity-1;j++)
	newQ[j].key=deleteQ();
	f=2*capacity-1;
	r=capacity-2;
	capacity*=2;
        free(q);
        q=newQ;
  }
  r=(r+1)%capacity;
  printf("Enter element to be inserted\n");
  scanf("%d",&q[r].key);
}
int deleteQ()
{
 f=(f+1)%capacity;
 return q[f].key;
}
void display()
{
  for(int i=(f+1)%capacity;i!=(r+1)%capacity;i=(i+1)%capacity)
  printf("%d\n",q[i].key);
}
void main()
{
  int c;
  q=(element*)malloc(sizeof(element));
  while(1)
  {
    printf("1)Insert 2)Delete 3)Display 4)exit\n");
    scanf("%d",&c);
    switch(c)
    {
	case 1: addQ();
		break;
	case 2: if(f==r)
		printf("Queue empty\n");
		else
 		printf("Deleted element=%d\n",deleteQ());
		break;
 	case 3: display();
		break;
	case 4:exit(0);
	default:printf("Invalid choice\n");
    }
  }
}






