#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve(int n){
	if(n == 0 || n == 1 || n == 2){
		return n;
	}
	return solve(n-1) + (n-1)*solve(n-2);
}



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		cout<<solve(n)<<endl;
	}




	return 0;
}