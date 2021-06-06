#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, h, x, val;
	cin>>n>>h>>x;
	if(x >= h){
		cout<<"YES";
		return 0;
	}
	for(int i = 0; i < n; i++){
		cin>>val;
		if(val + x == h){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";

	return 0;
}