#ifndef HEADER_FILE
#define HEADER_FILE

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
	
using namespace std;


int save(string s);
string lookup(int n);
int yylex(void);
void yyerror(const char *);

#endif
