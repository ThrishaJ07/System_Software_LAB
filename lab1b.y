%{  
	#include<stdio.h>
%}
%token num ENTER
%left '+''-'
%left '*''/'
%%
input:expr ENTER{printf("Result is%d\n",$$); exit(0);}
expr: expr '+' expr{$$=$1+$3;}
|expr '-' expr{$$=$1-$3;}
|expr '*' expr{$$=$1*$3;}
|expr'/'expr{if($3==0){printf("devide by zero error\n");}else $$=$1/$3;}
|'('expr')'{$$=$2;}
|'-'expr{$$=$2;}
|num {$$=$1;};


%%
void main()
{
	printf("Enter the Expression\n");
	yyparse();
}
int yyerror()
{
	printf("Invalid Expression\n");
	exit(0);
}
  
