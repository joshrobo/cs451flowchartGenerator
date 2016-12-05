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
%type <s> sexpr
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
	FILE *fchart = fopen("fchart.dot", "w");
	int nc = 0;
	int depth = 0;
	int maxdepth = 0;
	int maxnode = 0;
	//assumes a recursive depth of less than 101
	int junk[100];
	int junkSize = sizeof(junk)/sizeof(junk[0]);
%}


%%


program: program fndef | {cout << "ready" << endl; }
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
    	statements statement   	{ 
									$$ = saveStatements(lookupStatements($1) + lookup($2) + "\\n");
									
								} 
    	| 			{ $$ = saveStatements("");}
    	;
statement:
	//assignment 
	TYPE ID '=' exp ';' 		{ junk[depth]++; }
	//void function call		
	| ID'('params')'';' 		{ junk[depth]++; }
	//non-void function call
	| ID '=' ID'('params')'';' 	{ junk[depth]++; }
	//if expression		
	| IF sexpr block 	
	{
		//cout << depth << "\n";
		//determine current node based on depth
		int current = nc + depth;
		for(int i = depth - 1; i >= 0; i--) {
			current += junk[i];
		}
		/*
		int top = nc + depth;
		for(int i = depth - 1; i >= 0; i--) {
			top += junk[i];
		}
*/
		fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", current, current + 1, current, lookup($2).c_str());


		//check if end node highest
		if(current + 1 + junk[depth] > maxnode) {
			maxnode = current + junk[depth] + 1;
		}
		fprintf(fchart, "%d->%d\n", current, maxnode);
		
		if(depth > maxdepth){
			maxdepth = depth;
		}

		//junk[depth] = 0;

		depth--;
		//set node count at end of recursion to highest numbered node
		if(depth == 0) {
			for(int i = maxdepth; i >= 0; i--) {
				junk[i] = 0;
			}
			nc = maxnode;
			maxnode = 0;
			junk[depth] = 0;
			maxdepth = 0;
		}
	}
	//while expression
	| WHILE '(' expr ')' block 	{cout << "while expression found" << endl;
					}
	//if_else expression
    	| IF '(' expr ')' block ELSE block {cout << "if else expression found" << endl;
					   }

    	| block
    	| ';'
    	| expr ';'           	
		{ 
			$$ = save(lookup($1)+";");
			
			if(depth > maxdepth){
				maxdepth = depth;
			}

			int current = nc + maxdepth;
			junk[depth]++;

			

			for(int i = maxdepth; i >= 0; i--) {
				current += junk[i];
			}
			
//cout << maxdepth;
			fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", current, current + 1, current, lookup($1).c_str());
		}
	;

expr:
	exp			{ $$ = save(lookup($1)); }
	
	//expression using comparsion operators
	| exp COP exp		{ string s = lookup($1); 
			  	  s += lookupOP($2);
			  	  s += lookup($3);
			 	  $$ = save(s); }  

	//expression using arithmetic operators	(e.g. +=, -=)		
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

//special expression that tracks recursive depth
sexpr:
	'(' exp ')'	{ 
					$$ = save(lookup($2)); 
					depth++;
				}
	
	//expression using comparsion operators
	| '(' exp COP exp ')'	{ 
								string s = lookup($2); 
						  	  	s += lookupOP($3);
						  	  	s += lookup($4);
						 	  	$$ = save(s); 
								depth++;
							}  

	//expression using arithmetic operators	(e.g. +=, -=)		
	| '(' ID AOP exp ')'	{
								string s = lookup($2); 
					  	  		s += lookupOP($3);
					  	  		s += lookup($4);
					 	  		$$ = save(s);
								depth++; 
							} 
	//assignment operator
	| '(' ID '=' exp ')'	{
								string s = lookup($2); 
					  	  		s += "=";
					  	  		s += lookup($4);
					 	  		$$ = save(s); 
								depth++;
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
    	;	 
%%


void yyerror(const char *s) {
	cerr << s << endl;
}


int main(void) {
	fprintf(fchart, "digraph {\nnode [shape=circle]\n");
	for(int i = 0; i < junkSize; i++) {
		junk[i] = 0;
	}
	yyparse();
	fprintf(fchart, "}");
	fclose(fchart);
	return 0;
}





























