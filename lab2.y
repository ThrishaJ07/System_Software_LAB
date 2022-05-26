%{
	#include<stdio.h>
%}
%%
stmt: s ENTER{printf("valid grammar");exit(0);}
s : AsB
|
%%
void main()
{
	printf("Enter the string\n");
	yyparse();
}


