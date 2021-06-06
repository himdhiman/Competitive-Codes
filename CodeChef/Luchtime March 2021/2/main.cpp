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
		int e, r, m;
		cin>>e>>r>>m;
		m *= 60;
		r *= 60;
		if(r > m){
			cout<<"NO"<<endl;
		}else if(r <= e){
			cout<<"YES"<<endl;
		}else if(e + 2*(r-e) <= m){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	


	return 0;
}