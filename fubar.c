#include "fubar.h"

vector <string> data, dataOP;
int save(string s){
	int n = data.size();
	data.push_back(s);
	return n;
}

int saveOP(string s){
	int n = dataOP.size();
	dataOP.push_back(s);
	return n;
}

string lookup(int n){
	return data[n];
}
string lookupOP(int n){
	return dataOP[n];
}
