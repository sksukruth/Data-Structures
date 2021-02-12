#include<stdio.h>
typedef enum precedence
{lparen,rparen,plus,minus,multiply,divide,mod,eos,operand}precedence;
int isp[]={0,19,12,12,13,13,13,0};
int icp[]={20,19,12,12,13,13,13,0};
int stack[100];
char expr[100];
int top=-1;
precedence getToken(char* symbol,int* n)
{
	*symbol=expr[(*n)++];
	switch(*symbol)
	{
		case '(' : return lparen;
		case ')' : return rparen;
		case '+' : return plus;
		case '-' : return minus;
		case '*' : return multiply;
		case '/' : return divide;
		case '%' : return mod;
		case '' : return eos;
		case '\0' : return eos;
		default : return operand;
	}
}
void printToken(precedence token)
{
	switch(token)
	{
		case lparen : printf("(");
			      break;
		case rparen : printf(")");
			      break;
	        case plus : printf("+");
			    break;
		case minus : printf("-");
			     break;
		case multiply : printf("*");
				break;
		case divide : printf("/");
			      break;
		case mod : printf("%");
			   break;
		case eos : printf("");
			   break;
		case 8 : break;
	}
}
void push(int token)
{
	stack[++top]=token;
}
int pop()
{
	return stack[top--];
}
void postfix(void)
{
}
int main()
{
	printf("Enter the expression\n");
	scanf("%s",expr);
	postfix();
}


