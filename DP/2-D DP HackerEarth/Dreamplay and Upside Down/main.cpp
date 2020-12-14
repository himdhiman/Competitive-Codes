#include<bits/stdc++.h>
#define int long long
using namespace std;

string s;
const int N = 5001;
int dp[N][N];

int solve(int l, int r){
	if(l == r){
		if(s[l] == s[r]){
			return 0;
		}else{
			return 1;
		}
	}
	if(l+1 == r){
		if(s[l+1] == s[r]){
			return 0;
		}else{
			return 1;
		}
	}
	if(dp[l][r] != -1){
		return dp[l][r];
	}
	if(s[l] != s[r]){
		return dp[l][r] = 1 + min(solve(l+1, r), solve(l+1, r-1));
	}else{
		return dp[l][r] = solve(l+1, r-1);
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	getline(cin, s);
	int n = s.length();
	memset(dp, -1, sizeof dp);
	cout<<solve(0, n-1);
	


	return 0;
}