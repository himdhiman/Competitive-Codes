#include<bits/stdc++.h>
using namespace std;

bool EqualSumPartition(int n, int * arr, int sum){
	if(sum % 2 != 0){
		return false;
	}
	int actual_sum = sum/2;

	int dp[n+1][actual_sum+1];

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= actual_sum; j++){
			if(j == 0){
				dp[i][j] = true;
			}else if(i == 0){
				dp[i][j] = false;
			}else if(arr[i] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = dp[i-1][j-arr[i]] || dp[i-1][j];
			}
		}
	}
	return dp[n][actual_sum];
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	int sum = 0;
	cin>>n;
	// cout<<n<<endl;
	int * arr = new int[n+1];
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
		sum += arr[i];
	}
	cout<<EqualSumPartition(n, arr, sum);

}