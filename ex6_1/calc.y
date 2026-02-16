%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void yyerror(const char *s);
int yylex();
%}

%union{double dval;}
%token <dval> NUMBER
%token CEIL FLOOR
%type <dval> expression
%left '-'
%left '/'

%%
input:
|input line;
line:
'\n'
|expression '\n'{printf("Result: %g\n",$1);};
expression:
expression'-'expression{$$=$1-$3;}
|expression'/'expression{if($3==0){printf("Error: Division by zero\n");exit(1);}$$=$1/$3;}
|CEIL'('expression')'{$$=ceil($3);}
|FLOOR'('expression')'{$$=floor($3);}
|'('expression')'{$$=$2;}
|NUMBER{$$=$1;};
%%

void yyerror(const char *s){printf("Syntax Error\n");}
int main(){printf("Enter expressions (Ctrl+D to exit):\n");yyparse();return 0;}
