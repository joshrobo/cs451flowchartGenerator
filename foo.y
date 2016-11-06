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
%token <s> WHILE
%token <s> ELSE
%token <s> OP
%type <s> expr
%type <s> oper
%type <s> iexpr
%type <s> sexpr
%type <s> ifexpr
%type <s> whexpr
%type <s> else


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
	ifexpr '(' iexpr ')' block 	{cout << "if expression found" << endl;}
	| whexpr '(' iexpr ')' block 	{cout << "while expression found" << endl;}
    	| ifexpr '(' iexpr ')' block else block {cout << "if else expression found" << endl;}
    	| block
    	| ';'
    	| expr ';'           	{ cout << "floating point expression " << fixed << setprecision(2) << $1 << endl; }
    	| iexpr ';'          	{ cout << "integer expression: " << fixed << setprecision(0) << lookup($1) << endl; }
    	| sexpr ';' 		{ cout  << "string: " << '"' << lookup($1) << '"' << endl; }
	;
expr:
    	FLOATPT              	{ $$ = $1; }
    	| expr '+' expr      	{ $$ = $1 + $3; }
    	| expr '+' iexpr     	{ $$ = $1 + $3; }
    	| iexpr '+' expr     	{ $$ = $1 + $3; }
    	;
iexpr:
    	INTEGER              	{ $$ = save(to_string($1)); }
    	| iexpr oper iexpr    	{ 
    				 string s = lookup($1); 
				  cout << "iexpr: " << s << endl;
				  s += lookupOP($2);
				  cout << "iexpr oper: " << s << endl;
				  s += lookup($3);
				  cout << "iexpr oper iexpr: " << s << endl;
  				  $$ = save(s); }
    	;

oper:  OP 			{ $$ = saveOP(to_string($1));}
	;
sexpr: 
	STRING 			{ $$ = $1; cout << $1 << endl; }
	; 
ifexpr: IF		{$$ = $1;}
	;
whexpr: WHILE		{$$ = $1;}
	;
else: 	ELSE		{$$ = $1;}
	;
   	 
%%


void yyerror(const char *s) {
	cerr << s << endl;
}


int main(void) {
	yyparse();
	return 0;
}
