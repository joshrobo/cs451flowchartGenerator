%{
	#include "foo.tab.h"
	#include "fubar.h"
%}


num_with_pt [0-9]*\.[0-9]+|[0-9]+\.[0-9]*


%%

if 		{return IF;}
while 		{return WHILE;}
else		{return ELSE;}

{num_with_pt} {  // first
            	stringstream(yytext) >> yylval.x;  
            	return FLOATPT;
        	}


[0-9]+  	{
            	stringstream(yytext) >> yylval.i;  
            	return INTEGER;
        	}
\'.\'		{
		string s = yytext;
		yylval.s = save(s);
		return CHAR;
}
		

(int|char|short|long|double|float)(\*)*	{      	
				string s = yytext;
				yylval.s = save(s); 
		           	return TYPE;
        	}

((int|char|short|long|double|float)(\*)* [a-zA-Z_]+,)*(int|char|short|long|double|float)(\*)*[a-zA-Z_]+)	{
				string s = yytext;
				yylval.s = save(s); 
		           	return PARAMS;
				}

[a-zA-Z_]+  	{      	
				string s = yytext;
				yylval.s = save(s); 
		           	return ID;
        	}

\"[^"]*\"		{
			string s = yytext;
			yylval.s = save(s); 
			
			return STRING;
		}
=		{
			return *yytext;
		}

[-+*/\%]?=	{
			string s = yytext;
			yylval.s = saveOP(s);
			return AOP; }

[-+*/\%]		{
			string s = yytext;
			yylval.s = saveOP(s);
			return OP;}

==|!=|>|<|<=|>=	{
			string s = yytext;
			yylval.s = saveOP(s);
			return COP; }

--|\+\+		{
			string s = yytext;
			yylval.s = saveOP(s);
			return IOP; }


[=;(){}]  	return *yytext;


[ \t\n]   	; /* skip whitespace */


.       	yyerror("invalid character");
%%


int yywrap(void) {
	return 1;
}
