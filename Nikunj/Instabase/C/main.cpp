#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1005;
int dp[1005][1005];

int x, y;

int solve(int b, int c){
	if(b == 0){
		return 0;
	}
	if(dp[b][c] != -1){
		return dp[b][c];
	}
	if(c < x){
		return solve(b-1, c+y);
	}
	return dp[b][c] = max(1 + solve(b-1, c-x), solve(b-1, c+y));
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int b, c;
	cin>>b>>c>>x>>y;
	memset(dp, -1, sizeof dp);
	cout<<solve(b, c);

	


	return 0;
}