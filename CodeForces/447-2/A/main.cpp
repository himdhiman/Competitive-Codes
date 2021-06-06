#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int dp[101][4];

int solve(string s, string t, int l1, int l2){
	if((l1 == 0 and l2 == 0) || l2 == 0){
		return 1;
	}
	if(l1 == 0){
		return 0;
	}
	if(dp[l1][l2] != -1){
		return dp[l1][l2];
	}
	if(s[l1-1] != t[l2-1]){
		return dp[l1][l2] = solve(s, t, l1-1, l2);
	}
	return dp[l1][l2] = solve(s, t, l1-1, l2-1) + solve(s, t, l1-1, l2);

}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	string s;
	cin>>s;
	string t = "QAQ";
	memset(dp, -1, sizeof dp);
	cout<<solve(s, t, s.length(), t.length());
	


	return 0;
}