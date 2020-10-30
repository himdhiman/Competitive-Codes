#include<bits/stdc++.h>
#define int long long
using namespace std;



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	vector<int> v(n);
	int XOR = 0;
	for(int i = 0; i < n; i++){
		cin>>v[i];
		XOR ^= v[i];
	}
	int ans = LLONG_MIN;
	for(int i = 0; i < n; i++){
		ans = max(ans, XOR^v[i]);
	}
	ans = max(ans, XOR);
	cout<<ans;





	return 0;
}