#include<bits/stdc++.h>
using namespace std;

int CountSubsets(int n, int * arr, int s){
	if(s == 0){
		return 1;
	}
	if(s < 0 || n == 0){
		return 0;
	}

	if(arr[n] > s){
		CountSubsets(n-1, arr, s);
	}

	return CountSubsets(n-1, arr, s-arr[n]) + CountSubsets(n-1, arr, s);
}

int CountSubsetsDP(int n, int * arr, int s){
	int dp[n+1][s+1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= s; j++){
			if(j == 0){
				dp[i][j] = 1;
			}else if(i == 0){
				dp[i][j] = 0;
			}else if(arr[i] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j-arr[i]]+dp[i-1][j];
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
	cout<<CountSubsets(n, arr, s)<<endl;
	cout<<CountSubsetsDP(n, arr, s)<<endl;	


}