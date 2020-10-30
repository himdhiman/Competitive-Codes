#include<iostream>
#include <climits>
#include<vector>
#include<cstring>
#define mod 1000000007
using namespace std;

long long int Paths(char arr[][1001], int r, int c){
	long long int dp[r+1][c+1];
	for(int i = 0; i <= r; i++){
		for(int j = 0; j <= c; j++){
			if(i == 0 || j == 0 || arr[i][j] == '#'){
				dp[i][j] = 0;
			}else if(i == 1 && j == 1){
				dp[i][j] = 1;
			}else{
				dp[i][j] = ((dp[i-1][j] % mod) + (dp[i][j-1]%mod) )% mod;
			}
		}
	}

	return dp[r][c];
}



int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int r, c;
	cin>>r>>c;
	char arr[1001][1001];
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			cin>>arr[i][j];
		}
	}
	
	cout<<Paths(arr, r, c);

}