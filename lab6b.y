%{
	#include<stdio.h>
	int id=0,op=0,digit=0,keyword=0;
	extern FILE*yyin;
	int yyerror();
%}
%token ID
%token OP
%token DIGIT
%token KEYWORD
%%
input:ID input{id++;}
|ID{id++;}
|OP input{op++;}
|OP{op++;} 
|DIGIT input{digit++;}
|DIGIT{digit++;};    
|KEYWORD input{keyword++;}
|KEYWORD{keyword++;};
%%

void main()
{
	yyin=fopen("6bsample.txt","r");
	yyparse();
	printf("ID count is %d \n",id);
	printf("OP count is %d \n",op);
	printf("DIGIT count is %d \n",digit);
	printf("KEYWORD count is %d \n",keyword);
}
int yyerror()
{
	printf("Invalid Expression\n");
}
  
	 
