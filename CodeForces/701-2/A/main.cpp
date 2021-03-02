#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// int dp[]

int solve(int a, int b){
	if(a == 0){
		return 0;
	}
	if(b > a){
		return 1;
	}
	return 1 + min(solve(ceil(a/b), b), solve(a, b+1));
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int a, b;
		cin>>a>>b;
		cout<<solve(a, b)<<endl;
	}


	


	return 0;
}