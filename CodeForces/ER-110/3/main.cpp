#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	string s;
	cin>>s;
	int n = s.length();
	int dp[n][2];
	memset(dp, 0, sizeof dp);
	if(s[n-1] == '0'){
		dp[n-1][0] = 1;
	}else{
		dp[n-1][1] = 1;
	}
	int ans = max(dp[n-1][0], dp[n-1][1]);
	for(int i = n-2; i >= 0; i--){
		if(s[i] == '1'){
			dp[i][1] = dp[i+1][0] + 1;
			dp[i][0] = dp[i+1][0];
		}else if(s[i] == '0'){
			dp[i][0] = dp[i+1][1] + 1;
			dp[i][1] = dp[i+1][1];
		}else{
			dp[i][0] = dp[i+1][1] + 1;
			dp[i][1] = dp[i+1][0] + 1;
		}

		ans += max(dp[i][0], dp[i][1]);
	}
	for(int i = 0; i < n; i++){
		cout<<dp[i][0]<<" ";
	}
	cout<<endl;
	for(int i = 0; i < n; i++){
		cout<<dp[i][1]<<" ";
	}
	cout<<endl;
	cout<<ans<<endl;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}