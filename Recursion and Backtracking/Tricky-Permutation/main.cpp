#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<string> temp;

void Solve(string s, int i, int n){
	if(i == n){
		temp.push_back(s);
		return;
	}
	for(int k = i; k < n; k++){
		swap(s[i], s[k]);
		Solve(s, i+1, n);
		swap(s[i], s[k]);
	}
	return;
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	string s;
	getline(cin, s);
	int n = s.length();
	Solve(s, 0, n);
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin() ,temp.end()), temp.end());
	for(auto x : temp){
		cout<<x<<endl;
	}


	return 0;
}