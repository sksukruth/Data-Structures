#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define COMPARE(x,y) (x>y)?1:((x==y)?0:-1)
typedef struct 
{
	int expo;
	float coef;
}polynomial;
polynomial terms[100];
int avail=0;
void attach(float coefficient,int exponent)
{
        if(avail>=100)
        {
                exit(1);
        }
        terms[avail].expo=exponent;
        terms[avail].coef=coefficient;
        avail++;
}

void padd(int starta,int startb,int finisha,int finishb,int *startd,int *finishd)
{
	float coefficient;
	*startd=avail;
	while((starta<=finisha)&&(startb<=finishb))
	{
		switch(COMPARE(terms[starta].expo,terms[startb].expo))
		{
			case 1:
				attach(terms[starta].coef,terms[starta].expo);
				starta++;
				break;
			case -1:
				attach(terms[startb].coef,terms[startb].expo);
				startb++;
				break;
			case 0:
				coefficient=terms[starta].coef+terms[startb].coef;
				if(coefficient)
				attach(coefficient,terms[starta].expo);
				starta++;
				startb++;
				break;
		}
	}
	
	for(;starta<=finisha;starta++)
	{
		attach(terms[starta].coef,terms[starta].expo);
	}
	for(;startb<=finishb;startb++)
	{
		attach(terms[startb].coef,terms[startb].expo);
	}
	*finishd=avail-1;
}

void printpoly(int start,int finish)
{
	int i;
	printf("\n");
	for(i=start;i<=finish;i++)
	{
		if(i==finish)
			printf("%.2fx^%d",terms[i].coef,terms[i].expo);
		else
			printf("%.2fx^%d+",terms[i].coef,terms[i].expo);
	}
	printf("\n");
}
void main()
{
	int startd=0,finishd=0,starta=0,finisha=0,startb=0,finishb=0;
	int count=0;
	int n,expo,i;
	float coef;
	starta=avail;
	while(count!=2)
	{
		printf("Enter the number of terms of polynomial\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			printf("Enter the coefficient\n");
			scanf("%f",&coef);
			printf("Enter the exponent\n");
			scanf("%d",&expo);
			attach(coef,expo);
		}
		if(count==0)
		{
			finisha=avail-1;
			startb=avail;
		}
		if(count==1)
		{
			finishb=avail-1;
		}
		count++;
	}
	printf("Polynomial 1 is ");
	printpoly(starta,finisha);
	printf("Polynomial 2 is ");
	printpoly(startb,finishb);
	padd(starta,startb,finisha,finishb,&startd,&finishd);
	printf("Resultant polynomial is ");
	printpoly(startd,finishd);
}








