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
		int c, d, a;
		cin>>c;
		for(int i = 31; i >= 0; i--){
			if((c>>i)&1){
				d = (1<<(i+1));
				a = ((1<<i) - 1);
				break;
			}
		}
		int sum = d-c;
		int ans = a*(a+sum);
		cout<<ans<<endl;
	}
	


	return 0;
}