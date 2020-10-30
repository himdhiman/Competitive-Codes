#include<iostream>
using namespace std;

bool isWhitespace(char c){
	if(c == ' ' || c == '\n' || c == '\t' || c == '\r'){
		return true;
	}
	return false;
}



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 


	cout<<isWhitespace();



	return 0;
}