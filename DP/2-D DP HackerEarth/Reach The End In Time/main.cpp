#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000;
int visited[N][N];
int dp[N][N];
vector<string> grid;
int r, c, tme;

bool isSafe(int i, int j){
	if(i >= 0 and i < r and j >= 0 and j < c and grid[i][j] == '.' and visited[i][j] == 0){
		return true;
	}
	return false;
}


int solve(int i, int j){

	if(i == r-1 and j == c-1){
		return 0;
	}

	visited[i][j] = 1;
	if(dp[i][j] != -1){
		return dp[i][j];
	}
	int ans1 = INT_MAX, ans2 = INT_MAX, ans3 = INT_MAX, ans4 = INT_MAX;
	if(isSafe(i, j+1)){
		ans1 = 1 + solve(i, j+1);
	}
	if(isSafe(i+1, j)){
		ans2 = 1 + solve(i+1, j);
	}
	if(isSafe(i-1, j)){
		ans3 = 1 + solve(i-1, j);
	}
	if(isSafe(i, j-1)){
		ans4 = 1 + solve(i, j-1);
	}
	visited[i][j] = 0;

	return dp[i][j] = min(ans1, min(ans2, min(ans3, ans4)));
	
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	cin>>r>>c;
	string s;
	getline(cin, s);
	for(int i = 0; i < r; i++){
		getline(cin, s);
		grid.push_back(s);
	}
	cin>>tme;

	memset(dp, -1, sizeof dp);
	memset(visited, 0, sizeof dp);
	int ans = solve(0, 0);
	if(ans <= tme){
		cout<<"Yes";
	}else{
		cout<<"No";
	}

	return 0;
}