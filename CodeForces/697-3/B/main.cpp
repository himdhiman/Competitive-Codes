#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005;
int arr[2] = {2020, 2021};
int dp[N];

int solve(int n, int sum){
	if(sum == 0){
		return 1;
	}
	if(n == 0 || sum < 2020){
		return 0;
	}
	if(dp[sum] != -1){
		return dp[sum];
	}
	if(arr[n-1] > sum){
		return solve(n-1, sum);
	}
	return dp[sum] = (solve(n-1, sum) || solve(n, sum-arr[n-1]));
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	memset(dp, -1, sizeof dp);
	while(t--){
		int n;
		cin>>n;
		if(solve(2, n)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	


	return 0;
}