#include<iostream>
#include <climits>
#include<vector>
#include<cstring>
using namespace std;

int function(vector<int> graph[], int src, int dp[]){
	if(graph[src].size() == 0){
		return 0;
	}
	if(dp[src] != -1){
		return dp[src];
	}
	int ans = 0;
	for(auto x : graph[src]){
		int temp = 1 + function(graph, x, dp);
		ans = max(ans, temp);
	}

	return dp[src] = ans;
}

int Solve(vector<int> graph[], int n){
	int dp[100002];
	memset(dp, -1, sizeof(dp));
	int res = 0;
	for(int i = 1; i <= n; i++){
		res = max(res, function(graph, i, dp));
	}
	return res;
}



int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, u, v;
	cin>>n>>m;

	vector<int> graph[100002];

	for(int i = 1; i <= m; i++){
		cin>>u>>v;
		graph[u].push_back(v);
	}

	// for(int i = 1; i <= n; i++){
	// 	cout<<i<<" --> ";
	// 	for(auto x : graph[i]){
	// 		cout<<x<<" ";
	// 	}
	// 	cout<<endl;
	// }

	cout<<Solve(graph, n)<<'\n';
	// cout<<graph[4].size();

}