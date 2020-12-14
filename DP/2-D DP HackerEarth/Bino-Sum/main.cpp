#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int solve(int n, int p){
	int ans = 1;
	int prev = 1;
	for(int i = 1; i <= p; i++){	
		int temp = prev*(n-i+1)/i;
		ans = ((ans % MOD) + (temp % MOD)) % MOD;
		prev = temp%MOD;
	}
	return ans;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n, p;
		cin>>n>>p;
		cout<<solve(n, p)<<endl;
	}
	


	return 0;
}