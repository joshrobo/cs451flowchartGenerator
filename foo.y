%union {
	int i;
	float x;
	char c;
	int s;
}

%token <s> VOID
%token <s> TYPE
%token <s> ID
%token <s> RETURN
%token <x> FLOATPT
%token <i> INTEGER
%token <s> CHAR
%token <s> PARAMS
%token <s> STRING
%token <s> IF
%token <s> WHILE
%token <s> ELSE
%token <s> OP
%token <s> COP
%token <s> AOP
%token <s> IOP
%type <s> block
%type <s> statements
%type <s> statement
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


program: program fndef | {cout << "digraph {" << endl;}
    	;
fndef: VOID ID '(' params ')' block { cout << "void function defined" << endl;}
	| TYPE ID '(' params ')' returnblock { cout << "function defined" << endl;}
       	;

params: PARAMS params |
	TYPE ID |
	
	;

block: '{' statements '}'   { $$ = saveBlock(lookupStatements($2));} 	 
    	;

returnblock: '{' statements RETURN exp';' '}'    	 
    	;

statements:
    	statements statement   	{ $$ = saveStatements(lookupStatements($1) + lookup($2) + "\\n");   
				} 
    	| 			{ $$ = saveStatements("");}
    	;
statement:
	//assignment 
	TYPE ID '=' exp ';'
	//void function call		
	| ID'('params')'';'
	//non-void function call
	| ID '=' ID'('params')'';'
	//if expression		
	| IF '(' expr ')' block 	{int n = count();
					 cout << "if_expression" << n << " -> condition" << n << endl;
					 cout << "condition" << n << "[label =\"" << lookup($3) << "\"]" << endl; 
					 cout << "condition" << n << " -> block" << n << endl; 
					 cout << "block" << n << "[label = \"" <<  lookupBlock($5) << "\"]" << endl; 
										}
	//while expression
	| WHILE '(' expr ')' block 	{cout << "while expression found" << endl;
					}
	//if_else expression
    	| IF '(' expr ')' block ELSE block {cout << "if else expression found" << endl;
					   }

    	| block
    	| ';'
    	| expr ';'           	{ $$ = save(lookup($1)+";"); }
	;

expr:
	exp			{ $$ = save(lookup($1)); }
	
	//expression using comparsion operators
	| exp COP exp		{ string s = lookup($1); 
			  	  s += lookupOP($2);
			  	  s += lookup($3);
			 	  $$ = save(s); }  

	//expression using arithmetic operators	(eg. +=, -=)		
	| ID AOP exp		{ string s = lookup($1); 
			  	  s += lookupOP($2);
			  	  s += lookup($3);
			 	  $$ = save(s); 
				} 
	//assignment operator
	| ID '=' exp		{ string s = lookup($1); 
			  	  s += "=";
			  	  s += lookup($3);
			 	  $$ = save(s); 
				}
    	;

exp:
    	INTEGER              	{ $$ = save(to_string($1)); }
	| FLOATPT              	{ $$ = save(to_string($1)); }
	| ID	              	{ $$ = $1;}
	| CHAR			{ $$ = $1;}
    	| expr OP expr    	{ string s = lookup($1); 
			  	  s += lookupOP($2);
			  	  s += lookup($3);
			 	  $$ = save(s); 
				}
	//increment operator
	| ID IOP    		{ string s = lookup($1); 
			  	  s += lookupOP($2);
			 	  $$ = save(s); 
				}
	//STRING			{ $$ = $1; }
    	;	 
%%


void yyerror(const char *s) {
	cerr << s << endl;
}


int main(void) {
	yyparse();
	return 0;
}
