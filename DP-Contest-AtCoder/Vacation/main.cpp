#include<iostream>
#include <climits>
#include <vector>
using namespace std;

int Vacation(vector<vector<int> > input, int n){

	int dp[n][3];

	for(int i = 0; i < 3; i++){
		dp[0][i] = input[0][i];
	}
	
	for(int i = 1; i < n; i++){
		dp[i][0] = input[i][0] + max(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = input[i][1] + max(dp[i-1][2], dp[i-1][0]);
		dp[i][2] = input[i][2] + max(dp[i-1][1], dp[i-1][0]);
	}

	return max(dp[n-1][1], max(dp[n-1][2], dp[n-1][0]));

}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	vector<vector<int> > input(n, vector<int>(3));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++){
			cin>>input[i][j];
		}
	}
	cout<<Vacation(input, n)<<'\n';

	return 0;
}