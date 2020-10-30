#include<iostream>
#include <climits>
#include <vector>
using namespace std;

int Frog1(vector<int> input, int n, vector<int> dp){
	if(n <= 0){
		return 0;
	}
	if(dp[n] != INT_MAX){
		return dp[n];
	}
	int ans1 = INT_MAX, ans2 = INT_MAX;
	ans1 = abs(input[n]-input[n-1]) + Frog1(input, n-1, dp);
	if(n-2 >= 0){
		ans2 = abs(input[n]-input[n-2]) + Frog1(input, n-2, dp);
	}
	return dp[n] =  min(ans1, ans2);
}

int Frog1TopDown(vector<int> input, int n){
	vector<int> dp(n);
	dp[0] = 0;
	dp[1] = abs(input[0]-input[1]) + dp[0];
	for(int i = 2; i < n; i++){
		int ans1 = abs(input[i]-input[i-1]) + dp[i-1];
		int ans2 = abs(input[i]-input[i-2]) + dp[i-2];
		dp[i] = min(ans1, ans2);
	}
	return dp[n-1];
}

int main(){

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int n;
	cin>>n;
	vector<int> input(n);
	for(int i = 0; i < n; i++){
		cin>>input[i];
	}
	vector<int> dp(n+1);
	// memset(dp, INT_MAX, sizeof(dp));
	for(int i = 0; i <= n; i++){
		dp[i] = INT_MAX;
	}
	// cout<<Frog1(input, n-1, dp)<<endl;
	cout<<Frog1TopDown(input, n)<<endl;

	return 0;
}