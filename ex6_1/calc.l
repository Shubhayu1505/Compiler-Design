%{
#include "calc.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+(\.[0-9]+)?      { yylval.dval = atof(yytext); return NUMBER; }
[Cc][Ee][Ii][Ll]      { return CEIL; }
[Ff][Ll][Oo][Oo][Rr]  { return FLOOR; }
[-/()]                { return yytext[0]; }
[ \t]                 { }
\n                    { return '\n'; }
.                     { printf("Invalid character: %s\n", yytext); }
%%

int yywrap(){return 1;}
