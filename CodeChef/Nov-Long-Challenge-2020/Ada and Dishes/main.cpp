#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 6, K = 31;
int dp[N][K];
int arr[N];

bool subsetSum(int n, int target){
	if(target == 0){
		return true;
	}
	if(n <= 0){
		return false;
	}
	if(dp[n][target] != -1){
		return dp[n][target];
	}
	if(arr[n-1] > target){
		return subsetSum(n-1, target);
	}
	return dp[n][target] = subsetSum(n-1, target-arr[n-1]) || subsetSum(n-1, target);
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){

		int n, sum = 0;
		cin>>n;
		if(n == 0){
			cout<<0<<endl;
			continue;
		}
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			sum += arr[i];
		}
		if(n == 1){
			cout<<arr[0]<<endl;
			continue;
		}
		memset(dp, -1, sizeof dp);
		int max_range = (sum/2);
		int minimum = INT_MAX;
		for(int i = 1; i <= max_range; i++){
			if(subsetSum(n, i)){
				minimum = min(minimum, sum-2*i);
			}
		}
		cout<<((sum + minimum)/2)<<endl;
	

	}

	return 0;
}