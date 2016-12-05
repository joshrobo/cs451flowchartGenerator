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
	//open file to write digraph to
	FILE *fchart = fopen("fchart.dot", "w");
	//position of final node at the end of top level control structures
	int nc = 0;
	//recursive depth
	int depth = 0;
	//maximum recursive depth in this recursion
	int maxdepth = 0;
	//maximum node, place to continue after recursion complete
	int maxnode = 0;
	//assumes a recursive depth of less than 101
	//holds the number of junk (non-control) nodes at each level
	int junk[100];
	int junkSize = sizeof(junk)/sizeof(junk[0]);
	//number of control nodes at each level
	int atDepth[100];
	int atDepthSize = sizeof(atDepth)/sizeof(atDepth[0]);
	//stores current node for reuse in if else statements
	int storeCurrent[100];
	int storeCurrentSize = sizeof(storeCurrent)/sizeof(storeCurrent[0]);
	//stores the current file position for rewinding at the end of while and if else statements
	long int pos = 0;
	int lsize = 0;
%}


%%


program: program fndef | {cout << "ready" << endl; }
    	;
fndef: void '(' params ')' block 
	{ 
		if(junk[0] != 0) {
			nc = nc + junk[0] + 1;
			junk[0] = 0;
			fprintf(fchart, "%d[label = \"end_void\"]", nc);

		}
		else {
			fprintf(fchart, "%d[label = \"end_void\"]", nc);
		}
		
		
		
	}
	| type '(' params ')' returnblock { cout << "function defined" << endl;}
       	;

void:
	VOID ID
	{ 
		
		fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", nc, nc + 1, nc, lookup($2).c_str());
		//nc++;
	};

type:
	TYPE ID
	{ 
		
		fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", nc, nc + 1, nc, lookup($2).c_str());
		//nc++;
	};

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
    	| 			
		{ 
			$$ = saveStatements("");
				
		}
		
    	;
statement:
	//assignment 
	TYPE ID '=' exp ';'
		{ 
			$$ = save(lookup($1)+";");
			//check if greatest recursive depth
			if(depth > maxdepth){
				maxdepth = depth;
			}
			//get current node
			int current = nc;
			//increment number of junk nodes at this level
			junk[depth]++;
			//add number of junk nodes at all reached recursive levels
			for(int i = maxdepth; i >= 0; i--) {
				current += junk[i];
			}
			//add number of control nodes at all reached recursive levels
			for(int i = maxdepth; i >= 0; i--) {
			current += atDepth[i];
			}
			//if this is the last node increase last node
			if(current + 1 > maxnode) {
				maxnode = current + 1;
			}

			
			//cout << maxdepth;

			//store position to rewind if need
			pos = ftell(fchart);

			//add junk node to the graph
			fprintf(fchart, "%d->%d\n", current, current + 1);
			
			lsize = ftell(fchart) - pos;

			fprintf(fchart, "%d[label = \"%s\", shape = \"rectangle\"]\n", current, lookup($1).c_str());
			
		}

	//void function call		
	| ID'('params')'';'
		{ 
			$$ = save(lookup($1)+";");
			//check if greatest recursive depth
			if(depth > maxdepth){
				maxdepth = depth;
			}
			//get current node
			int current = nc;
			//increment number of junk nodes at this level
			junk[depth]++;
			//add number of junk nodes at all reached recursive levels
			for(int i = maxdepth; i >= 0; i--) {
				current += junk[i];
			}
			//add number of control nodes at all reached recursive levels
			for(int i = maxdepth; i >= 0; i--) {
			current += atDepth[i];
			}
			//if this is the last node increase last node
			if(current + 1 > maxnode) {
				maxnode = current + 1;
			}

			
			//cout << maxdepth;

			//store position to rewind if need
			pos = ftell(fchart);

			//add junk node to the graph
			fprintf(fchart, "%d->%d\n", current, current + 1);
			
			lsize = ftell(fchart) - pos;

			fprintf(fchart, "%d[label = \"%s\", shape = \"rectangle\"]\n", current, lookup($1).c_str());
			
		}


	//non-void function call
	| ID '=' ID'('params')'';'
		{ 
			$$ = save(lookup($1)+";");
			//check if greatest recursive depth
			if(depth > maxdepth){
				maxdepth = depth;
			}
			//get current node
			int current = nc;
			//increment number of junk nodes at this level
			junk[depth]++;
			//add number of junk nodes at all reached recursive levels
			for(int i = maxdepth; i >= 0; i--) {
				current += junk[i];
			}
			//add number of control nodes at all reached recursive levels
			for(int i = maxdepth; i >= 0; i--) {
			current += atDepth[i];
			}
			//if this is the last node increase last node
			if(current + 1 > maxnode) {
				maxnode = current + 1;
			}

			
			//cout << maxdepth;

			//store position to rewind if need
			pos = ftell(fchart);

			//add junk node to the graph
			fprintf(fchart, "%d->%d\n", current, current + 1);
			
			lsize = ftell(fchart) - pos;

			fprintf(fchart, "%d[label = \"%s\", shape = \"rectangle\"]\n", current, lookup($1).c_str());
			
		}

	//if expression		
	| IF sexpr block 	
	{
		//cout << depth << "\n";
		//determine current node
		int current = nc;
		//depth - 1 since depth is incremented before code run
		//add number of junk nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += junk[i];
		}

		
		//add number of control nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += atDepth[i];
		}

		//add node to graph linking to statements if true
		fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", current, current + 1, current, lookup($2).c_str());


		//check if end node highest, else swap end node
		if(current + junk[depth] + 1 > maxnode) {
			maxnode = current + junk[depth] + 1;
		}
		//connect false part to end of if statement
		fprintf(fchart, "%d->%d\n", current, maxnode);
		//check if this is the maximum recursive depth
		if(depth > maxdepth){
			maxdepth = depth;
		}

		
		//drop to next level
		depth--;
		
		//reset everything if bottom of recursion
		if(depth == 0) {
			for(int i = maxdepth; i >= 0; i--) {
				junk[i] = 0;
			}
			for(int i = maxdepth; i >= 0; i--) {
				atDepth[i] = 0;
			}
			//set node count at end of recursion to highest numbered node
			nc = maxnode - 1;
			maxnode = 0;
			junk[depth] = 0;
			maxdepth = 0;
		}
	}

	//while expression
	| WHILE sexpr block 	
	{
		if(junk[depth] > 0) {
			int curPos = ftell(fchart);
			fseek(fchart, pos, SEEK_SET);
			for(int i = 0; i < lsize; i++) {
				fprintf(fchart, " ");
			}
			fseek(fchart, curPos, SEEK_SET);
		}

		//cout << depth << "\n";
		//determine current node
		int current = nc;
		//depth - 1 since depth is incremented before code run
		//add number of junk nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += junk[i];
		}

		
		//add number of control nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += atDepth[i];
		}

		//add node to graph linking to statements if true
		if(junk[depth] > 0) {
			fprintf(fchart, "%d->%d[label=true]\n%d[label = \"%s\", shape=diamond]", current, current + 1, current, lookup($2).c_str());

			fprintf(fchart, "%d->%d\n%d[label = \"%s\"]", current + junk[depth], current, current, lookup($2).c_str());
		}
		else {
			fprintf(fchart, "%d->%d[label=true]\n%d[label = \"%s\", shape=diamond]", current, current, current, lookup($2).c_str());	
		}


		//check if end node highest, else swap end node
		if(current + junk[depth] + 1 > maxnode) {
			maxnode = current + junk[depth] + 1;
		}
		//connect false part to end of if statement
		fprintf(fchart, "%d->%d[label = false]\n", current, maxnode);
		//check if this is the maximum recursive depth
		if(depth > maxdepth){
			maxdepth = depth;
		}

		
		//drop to next level
		depth--;
		
		//reset everything if bottom of recursion
		if(depth == 0) {
			for(int i = maxdepth; i >= 0; i--) {
				junk[i] = 0;
			}
			for(int i = maxdepth; i >= 0; i--) {
				atDepth[i] = 0;
			}
			//set node count at end of recursion to highest numbered node
			nc = maxnode - 1;
			maxnode = 0;
			junk[depth] = 0;
			maxdepth = 0;
		}
	}

	//if_else expression
    | IF else block 
	{
		
		//cout << depth << "\n";
		//determine current node
		int current = nc;
		//depth - 1 since depth is incremented before code run
		//add number of junk nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += junk[i];
		}

		
		//add number of control nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += atDepth[i];
		}

		//link the top node of the if statement stored in storeCurrent to the first node of the else side
		fprintf(fchart, "%d->%d[label=\"false\"]\n", current, storeCurrent[depth - 1]);



		//check if end node highest, else swap end node
		if(current + junk[depth] + 1 > maxnode) {
			maxnode = current + junk[depth] + 1;
		}

		if(storeCurrent[depth - 1] - 1 != current) {
			fprintf(fchart, "%d->%d\n", storeCurrent[depth - 1] - 1, maxnode);

		}
		else {
			fprintf(fchart, "%d->%d[label=\"true\"]\n%d[label = \"%s\",  shape = \"diamond\"]", current, maxnode, current, lookup($1).c_str());
		}

		//check if this is the maximum recursive depth
		if(depth > maxdepth){
			maxdepth = depth;
		}

		
		//drop to next level
		depth--;
		
		//reset everything if bottom of recursion
		if(depth == 0) {
			for(int i = maxdepth; i >= 0; i--) {
				junk[i] = 0;
			}
			for(int i = maxdepth; i >= 0; i--) {
				atDepth[i] = 0;
			}
			for(int i = maxdepth; i >= 0; i--) {
				storeCurrent[i] = 0;
			}
			//set node count at end of recursion to highest numbered node
			nc = maxnode - 1;
			maxnode = 0;
			junk[depth] = 0;
			maxdepth = 0;
		}
	}

    	| block
    	| ';'
    	| expr ';'           	
		{ 
			$$ = save(lookup($1)+";");
			//check if greatest recursive depth
			if(depth > maxdepth){
				maxdepth = depth;
			}
			//get current node
			int current = nc;
			//increment number of junk nodes at this level
			junk[depth]++;
			//add number of junk nodes at all reached recursive levels
			for(int i = maxdepth; i >= 0; i--) {
				current += junk[i];
			}
			//add number of control nodes at all reached recursive levels
			for(int i = maxdepth; i >= 0; i--) {
			current += atDepth[i];
			}
			//if this is the last node increase last node
			if(current + 1 > maxnode) {
				maxnode = current + 1;
			}

			
			//cout << maxdepth;

			//store position to rewind if need
			pos = ftell(fchart);

			//add junk node to the graph
			fprintf(fchart, "%d->%d\n", current, current + 1);
			
			lsize = ftell(fchart) - pos;

			fprintf(fchart, "%d[label = \"%s\", shape = \"rectangle\"]\n", current, lookup($1).c_str());
			
		}
	;



else:
	sexpr block ELSE
	{
		if(junk[depth] > 0) {
			int curPos = ftell(fchart);
			fseek(fchart, pos, SEEK_SET);
			for(int i = 0; i < lsize; i++) {
				fprintf(fchart, " ");
			}
			fseek(fchart, curPos, SEEK_SET);
		}
		
		//cout << depth << "\n";
		//determine current node
		int current = nc;
		//depth - 1 since depth is incremented before code run
		//add number of junk nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += junk[i];
		}

		
		//add number of control nodes
		for(int i = depth - 1; i >= 0; i--) {
			current += atDepth[i];
		}
		
		//add node to graph linking to statements if true
		fprintf(fchart, "%d->%d[label=\"true\"]\n%d[label = \"%s\",  shape = \"diamond\"]", current, current + 1, current, lookup($1).c_str());


		//check if end node highest, else swap end node
		if(current + 1 + junk[depth] > maxnode) {
			maxnode = current + junk[depth] + 1;
		}

		//check if this is the maximum recursive depth
		if(depth > maxdepth){
			maxdepth = depth;
		}

		//store the first node of the second side
		storeCurrent[depth - 1] = maxnode;

	};

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
					//increment number of control nodes at this depth and increment depth
					atDepth[depth]++;
					depth++;
				}
	
	//expression using comparsion operators
	| '(' exp COP exp ')'	{ 
								string s = lookup($2); 
						  	  	s += lookupOP($3);
						  	  	s += lookup($4);
						 	  	$$ = save(s); 
								//increment number of control nodes at this depth and increment depth
								atDepth[depth]++;
								depth++;
							}  

	//expression using arithmetic operators	(e.g. +=, -=)		
	| '(' ID AOP exp ')'	{
								string s = lookup($2); 
					  	  		s += lookupOP($3);
					  	  		s += lookup($4);
					 	  		$$ = save(s);
								//increment number of control nodes at this depth and increment depth
								atDepth[depth]++;
								depth++; 
							} 
	//assignment operator
	| '(' ID '=' exp ')'	{
								string s = lookup($2); 
					  	  		s += "=";
					  	  		s += lookup($4);
					 	  		$$ = save(s); 
								//increment number of control nodes at this depth and increment depth
								atDepth[depth]++;
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
	//initialize digraph
	fprintf(fchart, "digraph {\nnode [shape=circle]\n");
	//initialize arrays
	for(int i = 0; i < junkSize; i++) {
		junk[i] = 0;
	}
	for(int i = 0; i < atDepthSize; i++) {
		atDepth[i] = 0;
	}
	for(int i = 0; i < storeCurrentSize; i++) {
		storeCurrent[i] = 0;
	}

	yyparse();
	//end digraph
	fprintf(fchart, "}");
	//close file
	fclose(fchart);
	return 0;
}





























