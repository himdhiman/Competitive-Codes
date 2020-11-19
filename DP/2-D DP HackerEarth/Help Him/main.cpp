#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000;
int arr[N][N];
int dp1[N][N];
int dp2[N][N];

int solve1(int n, int i, int j){
	if(i == n-1 and j == n-1){
		return arr[n-1][n-1];
	}
	if(dp1[i][j] != 0){
		return dp1[i][j];
	}
	if(i == n-1){
		return dp1[i][j] = arr[i][j] + solve1(n, i, j+1);
	}else if(j == n-1){
		return dp1[i][j] = arr[i][j] + solve1(n, i+1, j);
	}else{
		return dp1[i][j] = arr[i][j] + max(solve1(n, i+1, j), solve1(n, i, j+1));
	}
}

int solve2(int n, int i, int j){
	if(i == 0 and j == 0){
		return arr[0][0];
	}
	if(dp2[i][j] != 0){
		return dp2[i][j];
	}
	if(i == 0){
		return dp2[i][j] = arr[i][j] + solve2(n, i, j-1);
	}else if(j == 0){
		return dp2[i][j] = arr[i][j] + solve2(n, i-1, j);
	}else{
		return dp2[i][j] = arr[i][j] + min(solve2(n, i-1, j), solve2(n, i, j-1));
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>arr[i][j];
		}
	}
	memset(dp1, 0, sizeof dp1);
	memset(dp2, 0, sizeof dp2);
	cout<<solve1(n, 0, 0)<<" "<<solve2(n, n-1, n-1);


	


	return 0;
}