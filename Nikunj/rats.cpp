#include<bits/stdc++.h>
using namespace std;

int whiteRats(int n, int k){
	int start = k;
	int first = 0;
	int second = 0;
	int third = 0;
	int alive = 0;
	int died = 0;
	int var = 0;

	for(int i = 0; i < n; i++){
		third = second;
		died += third;
		second = first;
		var = 3*second; 
		first = start;
		var += 2*first;
		alive += var;
		start = var;
	}
	return alive-died+k;
}

int blackRats(int n, int k){
	int start = k;
	int first = 0;
	int second = 0;
	int alive = 0;
	int died = 0;
	int var = 0;

	for(int i = 0; i < n; i++){
		second = first;
		died += second;
		first = start;
		var = 3*first;
		alive += var;
		start = var;
	}
	return alive-died+k;
}




int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, k;
	cin>>n>>k;

	cout<<abs(whiteRats(n, k)- blackRats(n, k));

	return 0;
}