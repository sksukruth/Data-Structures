#include<stdio.h>
#include<stdlib.h>
void fail(char* pat,int failure[]);
int pmatch(char* string,char* pat,int failure[]);
int main()
{
	char string[100],pat[100];
	int failure[100];
	int i,j,n;
	printf("Enter the string\n");
	scanf("%s",string);
	printf("Enter the pattern\n");
	scanf("%s",pat);
	fail(pat,failure);
	printf("\n%s",pat);
	printf("\n");
	for(i=0;i<strlen(pat);i++)
		printf("%d\t",failure[i]);
	printf("\nPosition of pattern found at %d\n",(pmatch(string,pat,failure)+1));
}
void fail(char* pat,int failure[])
{
	int i,j,n;
	n=strlen(pat);
	failure[0]=-1;
	for(j=1;j<n;j++)
	{
		i=failure[j-1];
		while((pat[j]!=pat[i+1])&&(i>=0))
		i=failure[i];
		if(pat[j]==pat[i+1])
		failure[j]=i+1;
		else
	       	failure[j]=-1;
	}
}
int pmatch(char* string,char* pat,int failure[])
{ 
	int i=0,j=0;
	int lens=strlen(string);
	int lenp=strlen(pat);
	while(i<lens&&j<lenp)
	{
		if(string[i]==pat[j])
		{
			i++;
			j++;
		}
		else if(j==0)
		{
			i++;
		}
		else
			j=failure[j-1]+1;
	}	
	return ((j==lenp)?(i-lenp):-1);
}
