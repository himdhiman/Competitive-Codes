#include<bits/stdc++.h>
using namespace std;

int KnapSackRecursion(int n, int * value, int * weight, int w){
	if(w == 0 || n == 0){
		return 0;
	}
	if(weight[n] > w){
		KnapSackRecursion(n-1, value, weight, w);
	}
	return max(value[n]+KnapSackRecursion(n-1, value, weight, w-weight[n]), KnapSackRecursion(n-1, value, weight, w));
}

int KnapSackDP(int n, int * weight, int * value, int w, int dp[][100]){
	if(w == 0 || n == 0){
		return 0;
	}
	if(dp[n][w] != 0){
		return dp[n][w];
	}
	if(weight[n] > w){
		KnapSackDP(n-1, weight, value, w, dp);
	}
	return dp[n][w] = max(value[n]+KnapSackDP(n-1, weight, value, w-weight[n], dp), KnapSackDP(n-1, weight, value, w, dp));
}

int KnapSackBottomUp(int n, int * weight, int * value, int w){
	int dp[n+1][w+1];
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= w; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}else if(weight[i] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(value[i]+dp[i-1][j-weight[i]], dp[i-1][j]);
			}
		}
	}
	return dp[n][w];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int * value;
	int * weight;
	int w;
	int n;

	cin>>n;
	value = new int[n+1];
	weight = new int[n+1];

	for(int i = 1; i <= n; i++){
		cin>>value[i];
	}
	for(int i = 1; i <= n; i++){
		cin>>weight[i];
	}

	cin>>w;

	// cout<<KnapSackRecursion(n, value, weight, w)<<'\n';


	int dp[100][100];
	memset(dp, 0, sizeof(dp));

	cout<<KnapSackDP(n, weight, value, w, dp)<<'\n';

	cout<<KnapSackBottomUp(n, weight, value, w);


}