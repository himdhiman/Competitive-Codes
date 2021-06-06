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
		int x, a, b;
		cin>>x>>a>>b;
		cout<<(a+(100-x)*b)*10<<endl;
	}
	


	return 0;
}