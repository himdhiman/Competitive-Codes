#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int pc[N];
int fc[N];
int dp[101][N];

int solve(int n, int p){
	if(n == 0 || p == 0){
		return 0;
	}
	if(fc[n-1] > p){
		return solve(n-1, p);
	}
	if(dp[n][p] != -1){
		return dp[n][p];
	}
	return dp[n][p] = max(pc[n-1] + solve(n-1, p-fc[n-1]), solve(n-1, p));
	
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int n, p;
		cin>>n>>p;
		for(int i = 0; i < n; i++){
			cin>>pc[i]>>fc[i];
		}
		memset(dp, -1, sizeof dp);
		int prf = solve(n, p);
		int i = n-1, j = p;
		while(j >= 0 and prf == dp[i][j]){
			j--;
		}
		j++;
		cout<<j<<" "<<prf<<endl;

	}

	


	return 0;
}