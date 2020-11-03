#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 17;
int dp[N][(1<<N)];


int solve(vector<int> A, vector<int> B, int index, int bitmask, int n){
	if(index == n){
		return 0;
	}
	if(dp[index][bitmask] != -1){
		return dp[index][bitmask];
	}
	int ans = LLONG_MAX;
	for(int i = 0; i < n; i++){
		if(!((bitmask>>i)&1)){
			int temp = A[index]^B[i] + solve(A, B, index+1, bitmask|(1<<i), n);
			ans = min(ans, temp);
		}
	}
	return dp[index][bitmask] = ans;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	vector<int> A(n, 0), B(n, 0);
	
	for(int i = 0; i < n; i++){
		cin>>A[i];
	}
	for(int i = 0; i < n; i++){
		cin>>B[i];
	}
	memset(dp, -1, sizeof dp);

	cout<<solve(A, B, 0, 0, n);

	return 0;
}