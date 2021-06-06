#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, val;
	cin>>n;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>val;
		sum += val; 
	}
	sum %= MOD;
	int q;
	cin>>q;
	for(int i = 0; i < q; i++){
		sum += sum;
		sum %= MOD;
		cout<<sum<<endl;
	}
	// cout<<(q*sum)%MOD<<endl;

	


	return 0;
}