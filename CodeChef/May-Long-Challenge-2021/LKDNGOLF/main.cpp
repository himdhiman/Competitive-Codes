#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n, x, k;
		cin>>n>>x>>k;
		if(x % k == 0 || ((n+1) % k == x % k) ){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	


	return 0;
}