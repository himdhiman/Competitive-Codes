#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int hire, sal, sev;

int solve(int n){

	int dp[42][n+1];
	for(int i = 0; i <= 41; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = INT_MAX;
		}
	}

	for(int i = arr[1]; i <= 41; i++){
		dp[i][1] = i*(hire+sal);
	}

	for(int i = 2; i <= n; i++){
		for(int j = arr[i-1]; j <= 41; j++){
			for(int k = arr[i]; k <= 41; k++){
				if(k < j){
					dp[k][i] = min(dp[k][i], dp[j][i-1] + sev*(j-k) + sal*k);
				}else if(k == j){
					dp[k][i] = min(dp[k][i] , dp[j][i-1] + sal*(k));
				}else {
					dp[k][i] = min(dp[k][i], dp[j][i-1] + hire*(k-j) + sal*k);
				}
			}
		}
	}

	int ans = INT_MAX;
	for(int i = 1; i <= 41; i++){
		ans = min(ans, dp[i][n]);
	}
	return ans;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>hire>>sal>>sev>>n;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	cout<<solve(n);

	


	return 0;
}