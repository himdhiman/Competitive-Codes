#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1001;
int dp[N][N];

int solve(string s1, string s2, int l1 , int l2){
	if(l1 == 0 || l2 == 0){
		return 0;
	}
	if(dp[l1][l2] != -1){
		return dp[l1][l2];
	}
	if(s1[l1-1] == s2[l2-1]){
		return 1 + solve(s1, s2, l1-1, l2-1);
	}

	return dp[l1][l2] = max(solve(s1, s2, l1-1, l2), solve(s1, s2, l1, l2-1));
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	string a, b;
	cin>>a;
	cin>>b;
	string s1 = a+b;
	string s2 = s1;
	reverse(s2.begin(), s2.end());
	memset(dp, -1, sizeof dp);
	cout<<solve(s1, s2, s1.length(), s2.length());


	


	return 0;
}