#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int row;
	int col;
	int val;
}term;
void input(term a[])
{
	int A[100][100],i,j,m,n,current;
	printf("Enter the number of rows\n");
	scanf("%d",&m);
	printf("Enter the number of cols\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			scanf("%d",&A[i][j]);
	current=1;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(A[i][j]!=0)
			{
				a[current].row=i;
				a[current].col=j;
				a[current].val=A[i][j];
				current++;
			}
		}
	}
	a[0].row=m;
	a[0].col=n;
	a[0].val=current-1;
}
void fast_transpose(term a[],term b[])
{
	int rowTerms[100],startingPos[100];
	int i,j,numCols=a[0].col,numTerms=a[0].val;
	b[0].col=numCols;
	b[0].row=a[0].row;
	b[0].val=numTerms;
	if(numTerms>0)
	{
	for(i=0;i<numCols;i++)
		rowTerms[i]=0;
	for(i=1;i<=numTerms;i++)
		rowTerms[a[i].col]++;
		startingPos[0]=1;

	for(i=1;i<numCols;i++)
		startingPos[i]=startingPos[i-1]+rowTerms[i-1];
	for(i=1;i<=numTerms;i++)
	{
		j=startingPos[a[i].col]++;
		b[j].row=a[i].col;
		b[j].col=a[i].row;
		b[j].val=a[i].val;
	}
	}		
}
void output(term k[])
{
	int i,num_terms;
	num_terms=k[0].val;
	printf("row\tcol\tvalue\n");
	for(i=0;i<=num_terms;i++)
		printf("%d\t%d\t%d\n",k[i].row,k[i].col,k[i].val);
}
int main()
{
	term a[101],b[101];
	printf("Enter the matrix\n");
	input(a);
	output(a);
	fast_transpose(a,b);
	output(b);
}
