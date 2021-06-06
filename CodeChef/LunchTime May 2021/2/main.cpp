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
		int n, k, q;
		cin>>n>>k;
		string s;
		cin>>s;
		int ans = 0;
		for(int i = 1; i < n; i++){
			if(s[i] == s[i-1]){
				ans += 2;
			}else{
				ans++;
			}
		}
		// cout<<ans<<endl;
		for(int i = 0; i < k; i++){
			cin>>q;
			int idx = q-1;
			if(s[idx] == '0'){
				s[idx] = '1';
			}else{
				s[idx] = '0';
			}
			if(idx - 1 >= 0){
				if(s[idx-1] == s[idx]){
					ans++;
				}else{
					ans--;
				}
			}	
			if(idx + 1 < n){
				if(s[idx] == s[idx+1]){
					ans++;
				}else{
					ans--;
				}
			}		
			cout<<ans<<endl;
			
		}
	}
	


	return 0;
}