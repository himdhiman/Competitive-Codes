#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000, M = 1000; 
int dp[N][M];
int fee[N], fun[N];

void solve(int fee[], int fun[], int budget, int n){
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= budget; j++){
			if(i == 0 || j == 0){
				dp[i][j] = 0;
			}else if(fee[i] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				if(fun[i] + dp[i-1][j-fee[i]] > dp[i-1][j]){
					dp[i][j] = fun[i] + dp[i-1][j-fee[i]];

				}else{
					dp[i][j] = dp[i-1][j];
				}
			}
		}
	}
	cout<<dp[n][budget]<<endl;
}





int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int budget, n;
	cin>>budget>>n;
	while(n != 0 and budget != 0){

		memset(dp, -1, sizeof dp);
		for(int i = 1; i <= n; i++){
			cin>>fee[i]>>fun[i];
		}
		solve(fee, fun, budget, n);

		cin>>budget>>n;
	}
	


	return 0;
}