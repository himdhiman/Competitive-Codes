#include<bits/stdc++.h>
#define int long long
using namespace std;

set<string> temp;

void Solve(string s, int i, int n){
	if(i == n){
		temp.insert(s);
		return;
	}
	for(int k = i; k < n; k++){
		swap(s[i], s[k]);
		Solve(s, k+1, n);
		swap(s[i], s[k]);
	}
	return;
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}
	string s = "";
	for(int i = 0; i < n; i++){
		s += to_string(v[i]);
	}
	int len = s.length();
	Solve(s, 0, len);



	for(auto x : temp){
		string t = x;
		string a = "";
		for(auto y : t){
			a += y;
			a += " ";
		}
		a.pop_back();
		cout<<a<<endl;
	}


	return 0;
}