#include<bits/stdc++.h>
using namespace std;

double dp[3001][3001];

double coinsF(double * arr, int i, int x, double dp[][3001]){
	if(x == 0){
		return 1;
	}
	if(i == 0){
		return 0;
	}
	if(dp[i][x] > -0.9){
		return dp[i][x];
	}
	return dp[i][x] = arr[i]*coinsF(arr, i-1, x-1, dp) + (1-arr[i])*coinsF(arr, i-1, x, dp);
}



int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	double * arr = new double[n+1];
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	

	int heads = (n+1)/2;

	memset(dp, -1, sizeof(dp));


	cout<< fixed << setprecision(10) << coinsF(arr, n, heads, dp);


	return 0;
}