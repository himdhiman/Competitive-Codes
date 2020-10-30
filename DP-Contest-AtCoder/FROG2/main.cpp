#include<iostream>
#include <climits>
#include <vector>
using namespace std;

// int Frog2(vector<int> input, int n, int k){
// 	if(n <= 0){
// 		return 0;
// 	}
// 	int ans = INT_MAX;
// 	for(int i = 1; i <= k && n-i >= 0; i++){
// 		int temp = abs(input[n] - input[n-i]) + Frog2(input, n-i, k);
// 		ans = min(ans, temp);
// 	}
// 	return ans;
// }

int Frog2BottomUp(vector<int> input, int n, int k){
	vector<int> dp(n);
	dp[0] = 0;
	for(int i = 1; i < n; i++){
		dp[i] = INT_MAX;
		for(int j = i-1; j >= 0 && (i-j) <= k; j--){
			dp[i] = min(dp[i], abs(input[i] - input[j]) + dp[j]);
		}
	}
	return dp[n-1];
}




int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin>>n>>k;
	vector<int> input(n);
	for(int i = 0; i < n; i++){
		cin>>input[i];
	}
	// cout<<Frog2(input, n-1, k)<<endl;
	cout<<Frog2BottomUp(input, n, k);

	return 0;
}