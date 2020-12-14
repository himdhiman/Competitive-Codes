#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
int arr[N][N];
int n;

int solve(int i, int j){
	if(i == n-1 and j == n-1){
		if(arr[i][j-1] >= arr[i][j] and arr[i-1][j] >= arr[i][j]){
			return 1;
		}
		if(arr[i][j-1] < arr[i][j] and arr[i-1][j] >= arr[i][j]){
			return solve(i, j-1);
		}
		if(arr[i-1][j] < arr[i][j] and arr[i][j-1] >= arr[i][j]){
			return solve(i-1, j);
		}
		return solve(i, j-1) + solve(i-1, j);

	}
	if(i == n-1 and j == 0){

	}
	if(i == 0 and j == n-1){

	}
	if(i == 0 and j == 0){

	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>arr[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			ans += solve(i, j);
		}
	}
	


	return 0;
}