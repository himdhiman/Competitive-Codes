#include<bits/stdc++.h>
#define int long long
using namespace std;

map<int, int> m;



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, val;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>val;
		m[val]++;
	}
	int ans = 0;
	for(auto x : m){
		int f = x.first;
		if(m.find(f+1) != m.end()){
			ans += min(m[f], m[f+1]);
		}
	}
	cout<<ans<<endl;

	


	return 0;
}