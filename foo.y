%union {
	int i;
	float x;
	char c;
	int s;
}


%token ID
%token <x> FLOATPT
%token <i> INTEGER
%token <s> STRING
%token <s> IF
%type <x> expr
%type <i> iexpr
%type <s> sexpr
%type <s> ifexpr


%left '+'


%{
	#include "fubar.h"
%}


%%


program: program fndef | {cout << "program ready" << endl;}
    	;
fndef: type ID '(' params ')' block { cout << "function defined" << endl;}
    	;
type:   ID
    	;
params: ;


block: '{' statements '}'    	 
    	;
statements:
    	statements statement   	 
    	|
    	;
statement:
	ifexpr ';' {cout << "if expression found" << endl;}
    	| block
    	| ';'
    	| expr ';'           	{ cout << "floating point value " << fixed << setprecision(2) << $1 << endl; }
    	| iexpr ';'          	{ cout << "integer value " << fixed << setprecision(0) << $1 << endl; }
    	| sexpr ';' 		{ cout  << "string value" << '"' << lookup($1) << '"' << endl; }
	;
expr:
    	FLOATPT              	{ $$ = $1; }
    	| expr '+' expr      	{ $$ = $1 + $3; }
    	| expr '+' iexpr     	{ $$ = $1 + $3; }
    	| iexpr '+' expr     	{ $$ = $1 + $3; }
    	;
iexpr:
    	INTEGER              	{ $$ = $1; }
    	| iexpr '+' iexpr    	{ $$ = $1 + $3; }
    	;

sexpr: 
	STRING 			{ $$ = $1; cout << $1 << endl;}
	; 
ifexpr: IF 			{$$ = $1;}
	;
   	 
%%


void yyerror(const char *s) {
	cerr << s << endl;
}


int main(void) {
	yyparse();
	return 0;
}
