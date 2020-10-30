#include<iostream>
#include <climits>
#include <vector>
using namespace std;

long long int Knapsack(long long int n, long long int * val, long long int * wt, long long int w){
	
	// long long int max_val = n*1000; 

	long long int dp[2][w+1];


	for(long long int i = 0; i <= w; i++){
		dp[0][i] = 0;
	}

	for(long long int i = 1; i <= n; i++){
		for(long long int j = 0; j <= w; j++){
			if(j == 0){
				dp[1][j] = 0;
			}else if(wt[i] > j){
				dp[1][j] = dp[0][j];
			}else{
				dp[1][j] = max(val[i] + dp[0][j-wt[i]], dp[0][j]);
			}
		}
		for(long long int j = 0; j <= w; j++){
			dp[0][j] = dp[1][j];
		}
	}
	return dp[1][w];
}



int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	long long int n, w;
	cin>>n>>w;

	long long int * value = new long long int[n+1];
	long long int * weight = new long long int[n+1];

	for(long long int i = 1; i <= n; i++){
		cin>>weight[i]>>value[i];
	}

	cout<<Knapsack(n, value, weight, w);



	return 0;
}