%union {
	int i;
	float x;
	char c;
	int s;
}


%token <s> ID
%token <x> FLOATPT
%token <i> INTEGER
%token <s> STRING
%token <s> IF
%token <s> WHILE
%token <s> ELSE
%token <s> OP
%token <s> COP
%token <s> AOP
%token <s> IOP
%type <s> expr
%type <s> exp
/*
%type <s> oper
%type <s> coper
%type <s> aoper
%type <s> ioper
%type <s> sexpr
%type <s> ifexpr
%type <s> whexpr
%type <s> else
*/


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
		IF '(' expr ')' block 	{cout << "if expression found" << endl;}
		| WHILE '(' expr ')' block 	{cout << "while expression found" << endl;}
    	| IF '(' expr ')' block ELSE block {cout << "if else expression found" << endl;}
    	| block
    	| ';'
    	| expr ';'           	{ cout << "expression " << lookup($1) << endl; }
    	//| iexpr ';'          	{ cout << "integer expression: " << fixed << setprecision(0) << lookup($1) << endl; }
    	//| sexpr ';' 		{ cout  << "string: " << '"' << lookup($1) << '"' << endl; }
	;

expr:
    	exp COP exp	{ 
    			  	string s = lookup($1); 
				  	//cout << "iexpr: " << s << endl;
				  	s += lookupOP($2);
				  	//cout << "iexpr oper: " << s << endl;
				  	s += lookup($3);
				  	//cout << "iexpr oper iexpr: " << s << endl;
  				 	$$ = save(s); } 
		| exp
		| ID AOP exp	{
					string s = lookup($1); 
				  	//cout << "iexpr: " << s << endl;
				  	s += lookupOP($2);
				  	//cout << "iexpr oper: " << s << endl;
				  	s += lookup($3);
				  	//cout << "iexpr oper iexpr: " << s << endl;
  				 	$$ = save(s); } 
    	;

exp:
    	INTEGER              	{ $$ = save(to_string($1)); }
		| FLOATPT              	{ $$ = save(to_string($1)); }
		| ID	              	{ $$ = $1;}
    	| expr OP expr    	{ 
    			  	string s = lookup($1); 
				  	//cout << "iexpr: " << s << endl;
				  	s += lookupOP($2);
				  	//cout << "iexpr oper: " << s << endl;
				  	s += lookup($3);
				  	//cout << "iexpr oper iexpr: " << s << endl;
  				 	$$ = save(s); }
		| ID IOP    			{ 
    			  	string s = lookup($1); 
				  	//cout << "iexpr: " << s << endl;
				  	s += lookupOP($2);
  				 	$$ = save(s); }
    	;
/*
oper:  OP 			{ $$ = $1; }
	;
coper: COP			{ $$ = $1; }
	;
aoper: AOP			{ $$ = $1; }
	;
ioper: IOP			{ $$ = $1; }
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
*/
   	 
%%


void yyerror(const char *s) {
	cerr << s << endl;
}


int main(void) {
	yyparse();
	return 0;
}
