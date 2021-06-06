#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
vector<int> arr(N);
vector<vector<int> > val(N);
unordered_map<int, vector<int> > graph;

int dp[N][2];

void dfs(int curr, int par = -1){
	dp[curr][0] = dp[curr][1] = 0;
	for(auto x : graph[curr]){
		if(curr != par){
			dfs(x, curr);
			dp[curr][0] += max(abs(val[curr][0] - val[x][1]) + dp[curr][1], dp[curr][0] + abs(val[curr][1] - val[x][0]));
	        dp[curr][1] += max(abs(val[curr][1] - val[x][1]) + dp[curr][1], dp[curr][0] + abs(val[curr][1] - val[x][0])); 
		}
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		graph.clear();
		val.clear();
		arr.clear();
		int v, x, y;
		cin>>v;
		for(int i = 0; i < v; i++){
			cin>>x>>y;
			val[i+1] = {x, y};
		}
		for(int i = 0; i < v-1; i++){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}	
		dfs(1);
		cout<<max(dp[1][0], dp[1][1])<<endl;
	}

	


	return 0;
}