#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
vector<int> v;

int dp[2001][2001];

int solve(int n, int m, int curr){
	if(m == 0){
		return 1;
	}
	if(dp[m][curr] != -1){
		return dp[m][curr];
	}
	int ans = 0;
	for(int i = 1; i <= n/curr; i++){
		ans = (ans%MOD + solve(n, m-1, i*curr)%MOD)%MOD;
	}
	return dp[m][curr] = ans%MOD;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, m;
	cin>>n>>m;
	int ans = 0;
	memset(dp, -1, sizeof dp);
	ans += solve(n, m, (int)1);
	cout<<ans%MOD;

	// solve(n, m, (int)2);
	


	return 0;
}