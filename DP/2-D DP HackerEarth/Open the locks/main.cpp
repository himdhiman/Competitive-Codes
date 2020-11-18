#include<bits/stdc++.h>
#define int long long
using namespace std;

set<int> s;
int dp[100001][10];


int solve(int n, int digit){
	if(n == 0){
		return 1;
	}
	if(dp[n][digit] != -1){
		return dp[n][digit];
	}
	int ans = 0;
	for(int i = 0; i < 10; i++){
		if(s.find(digit + i) == s.end()){
			ans = (((ans % 1000000007) + (solve(n-1, i) % 1000000007))% 1000000007);

		}
	}
	return dp[n][digit] = ans;
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	s.insert(1);
	s.insert(2);
	s.insert(3);
	s.insert(5);
	s.insert(7);
	s.insert(11);
	s.insert(13);
	s.insert(17);
	int n;
	cin>>n;
	int ans = 0;
	for(int i = 0; i < 10; i++){
		memset(dp, -1, sizeof dp);
		ans += solve(n-1, i);
	}
	// int ans = solve(n, 0);
	cout<<ans;


	return 0;
}