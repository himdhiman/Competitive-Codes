#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
vector<int> arr(N, 0);
int dp[101][101];

int sum(int s, int e){
	int ans = 0;
	for(int i = s; i <= e; i++){
		ans += arr[i];
		ans %= 100;
	}
	return ans;
}

int solve(int i, int j){
	if(i >= j){
		return 0;
	}
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int ans = LLONG_MAX;
	for(int k = i; k < j; k++){
		int temp = solve(i, k) + solve(k+1, j) + sum(i, k)*sum(k+1, j);
		ans = min(ans, temp);
	}
	return dp[i][j] = ans;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 


	int n;
	while((scanf("%lld", &n)) != EOF){

		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		memset(dp, -1, sizeof dp);
		int j = arr.size()-1;
		cout<<solve(0, j)<<endl;
		fill(arr.begin(), arr.end(), 0);
	}

	return 0;
}