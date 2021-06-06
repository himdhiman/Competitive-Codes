#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

set<int> m;



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		m.clear();
		int n, x, val;
		cin>>n>>x;
		for(int i = 0 ; i < n; i++){
			cin>>val;
			m.insert(val);
		}
		if(n-x < m.size()){
			cout<<(n-x)<<endl;
		}else{
			cout<<m.size()<<endl;
		}
	}

	return 0;
}