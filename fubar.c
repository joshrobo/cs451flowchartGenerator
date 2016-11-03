#include "fubar.h"

vector <string> data;
int save(string s){
	int n = data.size();
	data.push_back(s);
	return n;
}
string lookup(int n){
	return data[n];
}
