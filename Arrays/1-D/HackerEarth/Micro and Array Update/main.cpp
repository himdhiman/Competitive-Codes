#include<bits/stdc++.h>
#define int long long
using namespace std;




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		vector<int> v(n, 0);
		int mn = INT_MAX;
		for(int i = 0; i < n; i++){
			cin>>v[i];
			mn = min(mn, v[i]);
		}
		int ans = k-mn;
		int z = 0;
		cout<<max(z, ans)<<endl;

	}
		


	return 0;
}