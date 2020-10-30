#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	getline(cin, s);
	int n = s.length();
	vector<int> dp(n, 0);
	int ans = 0;
	for(int i = 1; i < n; i++){
		if(s[i] == ')'){
			if(s[i-1] == '('){
				if(i-2 >= 0 and s[i-2] == ')'){
					dp[i] = dp[i-2] + 2;
				}else{
					dp[i] = 2;
				}
			}else{
				if(i-dp[i-1]-1 >= 0 and s[i-dp[i-1]-1] == '('){
					if(i-dp[i-1]-1 == 0){
						dp[i] = dp[i-1] + 2;
					}else{
						dp[i] = dp[i-dp[i-1]-2] + dp[i-1] + 2;
					}
				}
			}
		}
		ans = max(dp[i], ans);
	}
	if(ans == 0){
		cout<<"0 1";
		return 0;
	}
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(dp[i] == ans){
			cnt++;
		}
	}
	cout<<ans<<" "<<cnt;

	return 0;
}