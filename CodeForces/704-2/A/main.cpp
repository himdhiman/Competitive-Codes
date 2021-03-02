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
		int k, a, b, c;
		cin>>k>>a>>b>>c;
		cout<<min(a*ceil((k/(float)a)), min(b*ceil((k/(float)b)), c*ceil((k/(float)c)))) - k<<endl;
		// cout<<ans<<endl;
	}
	return 0;
}