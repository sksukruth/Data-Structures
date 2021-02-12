#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) (x>y)?1:((x==y)?0:-1)
typedef struct poly* polypointer;
typedef struct poly
{
	int exp;
	float coef;
	polypointer link;
}poly;
void attach(float coef,int exp,polypointer* ptr)
{
	polypointer temp;
	temp=(polypointer)malloc(sizeof(poly));
	temp->exp=exp;
	temp->coef=coef;
	(*ptr)->link=temp;
	(*ptr)=temp;
	(*ptr)->link=NULL;
}
polypointer cadd(polypointer a,polypointer b)
{
	polypointer c,endc,starta;
	float coefficient;
	int done=0;
	starta=a;
	a=a->link;
	b=b->link;
	c=(polypointer)malloc(sizeof(poly));
	c->exp=-1;
	endc=c;
	do
	{
		switch(COMPARE(a->exp,b->exp))
		{
			case 1:attach(a->coef,a->exp,&endc);
			       a=a->link;
			       break;
			 case -1:attach(b->coef,b->exp,&endc);
                               b=b->link;
                               break;
			 case 0:if(starta==a)
					done=1;
				else
				{
					coefficient=a->coef+b->coef;
					if(coefficient)
						attach(coefficient,a->exp,&endc);
					a=a->link;
					b=b->link;
					
				}break;
		}
	}while(!done);
	endc->link=c;
	return c;
}
void printpoly(polypointer k)
{
	k=k->link;
	printf("\n");
	while(((k->link)->exp)!=-1)
	{
		printf("%.2fx^%d+",k->coef,k->exp);
		k=k->link;
	}
	printf("%.2fx^%d",k->coef,k->exp);
}

int main()
{
	polypointer a,b,c,enda,endb;
	int i,n,exp;
	float coef;
	a=(polypointer)malloc(sizeof(poly));
	a->exp=-1;
	enda=a;
	b=(polypointer)malloc(sizeof(poly));
        b->exp=-1;
        endb=b;
	printf("Enter the number of terms of first poly\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("Enter the coefficient\n");
		scanf("%f",&coef);
		printf("Enter the exponent\n");
		scanf("%d",&exp);
		attach(coef,exp,&enda);
	}
	enda->link=a;
	printf("Enter the number of terms of second poly\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter the coefficient\n");
                scanf("%f",&coef);
                printf("Enter the exponent\n");
                scanf("%d",&exp);
                attach(coef,exp,&endb);
        }
        endb->link=b;
	c=cadd(a,b);
	printpoly(a);
	printpoly(b);
	printpoly(c);
}



        


