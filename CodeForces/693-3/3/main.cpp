#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 200005;
int arr[N];

void solve(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	int dp[n];
	for(int i = n-1; i >= 0; i--){
		if(i + arr[i] >= n){
			dp[i] = arr[i];
		}else{
			dp[i] = dp[i+arr[i]] + arr[i];
		}
	}
	// for(int i = 0; i < n; i++){
	// 	cout<<dp[i]<<" ";
	// }
	// cout<<endl;
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, dp[i]);
	}
	cout<<ans<<endl;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	// t = 1;
	cin>>t;
	while(t--) solve();

	


	return 0;
}