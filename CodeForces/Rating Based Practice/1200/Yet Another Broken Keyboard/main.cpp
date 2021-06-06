#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 26;
int arr[N] = {0};

int solve(int n){

	return 0;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, m;
	char chr;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i = 0; i < m; i++){
		cin>>chr;
		arr[chr-'a'] = 1;
	}
	int dp[n][2];
	memset(dp, 0, sizeof dp);
	if(arr[s[n-1]-'a'] == 1){
		dp[n-1][0] = 1;
	}
	for(int i = n-2; i >= 0; i--){
		if(arr[s[i]-'a'] == 1){
			dp[i][0] = dp[i+1][0] + 1;
			dp[i][1] = dp[i+1][0];
		}
	}
	int ans = 0;

	// for(int i = 0; i < n; i++){
	// 	cout<<dp[i][0]<<" ";
	// }
	// cout<<endl;
	// for(int i = 0; i < n; i++){
	// 	cout<<dp[i][1]<<" ";
	// }
	// cout<<endl;

	for(int i = 0; i < n; i++){
		ans += max(dp[i][0], dp[i][1]);
	}
	cout<<ans<<endl;

	


	return 0;
}