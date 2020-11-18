#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int> solve(vector<int> a, vector<int> b, int n){
	vector<int> result;
	for(int i = 0; i < n; i++){
		int ai = a[i];
		int bi = b[i];
		int x = (ai-bi);
		if(x >= 0){
			x = x/2;
			result.push_back(2*x + 3*(ai-x));
		}else{
			result.push_back(0);
		}

	}
	return result;
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	vector<int> a(n, 0), b(n, 0);
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		cin>>b[i];
	}

	vector<int> res = solve(a, b, n);
	for(auto x : res){
		cout<<x<<" ";
	}


	return 0;
}