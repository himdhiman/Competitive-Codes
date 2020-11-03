#include<bits/stdc++.h>
#define int long long
using namespace std;




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, x, ans, t;
	cin>>t;
	while(t--){
		cin>>n>>x;
		if(n == 1 || n == 2){
			ans = 1;
		}else{
			if((n-2)%x == 0){
				ans = 1 + (n-2)/x;
			}else{
				ans = 2 + (n-2)/x;
			}
		}
		cout<<ans<<endl;		
	}

	


	return 0;
}