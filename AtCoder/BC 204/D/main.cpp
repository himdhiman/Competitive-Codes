#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;
int dp[101][10001];

int Helper(int n, int sum1, int sum2, vector<int> &v){
	if(n == 0){
		return max(sum1, sum2);
	}
	if(dp[n][sum1] != -1){
		return dp[n][sum1];
	}
	return dp[n][sum1] = min(Helper(n-1, sum1+v[n-1], sum2, v), Helper(n-1, sum1, sum2+v[n-1], v));
}

void solve(){
	int n, val;
	cin>>n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin>>val;
		v.push_back(val);
	}
	memset(dp, -1, sizeof dp);
	cout<<Helper(n, 0, 0, v);
	return;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	t = 1;
	// cin>>t;
	while(t--) solve();

	


	return 0;
}