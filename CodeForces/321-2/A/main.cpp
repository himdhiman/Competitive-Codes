#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N], dp[N];

int solve(int n){
	int ans = 1;
	dp[0] = 1;
	for(int i = 1; i < n; i++){
		dp[i] = 1;
		if(arr[i] >= arr[i-1]){
			dp[i] = 1 + dp[i-1];
			ans = max(ans, dp[i]);
		}
	}
	return ans;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	cout<<solve(n);


	return 0;
}