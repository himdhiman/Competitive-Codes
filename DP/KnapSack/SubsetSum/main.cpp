#include<bits/stdc++.h>
using namespace std;

int SubsetSumRec(int * arr, int n, int s){
	if(s == 0){
		return true;
	}
	if(n <= 0 || s < 0){
		return false;
	}

	if(arr[n] > s){
		SubsetSumRec(arr, n-1, s);
	}
	return SubsetSumRec(arr, n-1, s - arr[n]) || SubsetSumRec(arr, n-1, s);
}

int SubsetSumDP(int * arr, int n, int s){
	int dp[n+1][s+1];
	for(int i = 0; i <= n ; i++){
		for(int j = 0; j <= s; j++){
			if(j == 0){
				dp[i][j] = 1;
			}else if(i == 0){
				dp[i][j] = 0;
			}else if(arr[i] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j-arr[i]] || dp[i-1][j];
			}
		}
	}
	return dp[n][s];
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, s;
	cin>>n;
	int * arr = new int[n+1];
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	cin>>s;

	cout<<SubsetSumRec(arr, n, s)<<'\n';
	cout<<SubsetSumDP(arr, n, s)<<'\n';
}