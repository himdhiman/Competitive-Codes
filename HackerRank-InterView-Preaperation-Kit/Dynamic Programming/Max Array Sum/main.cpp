#include<bits/stdc++.h>
// #define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];

// int dp[N];

// int solve(int n){
// 	if(n <= 0){
// 		return 0;
// 	}
// 	if(dp[n] != INT_MIN){
// 		return dp[n];
// 	}
// 	return dp[n] = max(arr[n-1] + solve(n-2), solve(n-1));
// }

int maxSubsetSum(vector<int> arr) {
	int n = arr.size();
    int dp[n];
    dp[0] = max(0, arr[0]);
    dp[1] = max(0, max(arr[0], arr[1]));
    for(int i = 2; i < n; i++){
    	dp[i] = max(dp[i-2], max(arr[i]+dp[i-2], dp[i-1]));
    }
    return max(dp[n-1], dp[n-2]);
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	// for(int i = 0; i < N; i++){
	// 	dp[i] = INT_MIN;
	// }
	int n;
	cin>>n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<maxSubsetSum(arr);
	


	return 0;
}