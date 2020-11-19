#include<bits/stdc++.h>
#define int long long
using namespace std;

// 

// int solve(int w, int n){
// 	if(n == 0 || w == 0){
// 		return 0;
// 	}

// 	if(W[n-1] > w){
// 		solve(w, n-1);
// 	}
// 	return max(V[n-1] + solve(w - W[n-1], n-1), solve(w, n-1));
// }

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




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	int * value;
	int * weight;
	while(t--){
		int n, w;
		cin>>n;
		cin>>w;
		value = new int[n+1];
		weight = new int[n+1];
		for(int i = 1; i <= n; i++){
			cin>>weight[i];
		}
		for(int i = 1; i <= n; i++){
			cin>>value[i];
		}
		cout<<KnapSackBottomUp(n, weight, value, w)<<endl;
	}


	return 0;
}