#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 101, T = 10001;
int dp[N][T];
int arr[N];

bool solve(int n, int target){
	if(target == 0){
		return true;
	}
	if(n == 0){
		return false;
	}
	if(dp[n][target] != -1){
		return dp[n][target];
	}
	if(arr[n-1] > target){
		return dp[n][target] = solve(n-1, target);
	}
	return dp[n][target] = solve(n-1, target-arr[n-1]) || solve(n-1, target);
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			sum += arr[i];
		}
		int cnt = 1;
		memset(dp, -1, sizeof dp);
		for(int i = 1; i <= sum; i++){
			if(solve(n, i)){
				cnt++;
			}
		}
		cout<<cnt<<endl;

	}	


	return 0;
}