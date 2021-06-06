#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	// solve();
	int t;
	cin>>t;
	while(t--){
		int n, m, k;
		cin>>n>>m>>k;
		if(n*m-1 == k){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	


	return 0;
}