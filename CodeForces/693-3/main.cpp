#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[101];
int dp[101][N];

int solve(int n, int sum){
	if(sum == 0){
		return 1;
	}
	if(n == 0){
		return 0;
	}
	if(dp[n][sum] != -1){
		return dp[n][sum];
	}
	if(sum < arr[n-1]){
		return dp[n][sum] = solve(n-1, sum);
	}
	return dp[n][sum] = (solve(n-1, sum) || solve(n-1, sum-arr[n-1]));
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
		memset(dp, -1, sizeof dp);
		if(sum % 2 == 1){
			cout<<"NO"<<endl;
		}else{
			if(solve(n, sum/2)){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}

	


	return 0;
}