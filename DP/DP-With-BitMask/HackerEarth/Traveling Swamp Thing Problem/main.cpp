#include<bits/stdc++.h>
#define int long long
using namespace std;

unordered_map<int, list<vector<int> > >graph;
int VISITED_ALL;
int dp[15][1<<15][101];


int solve(int curr, int mask, int energy){
	if(mask == VISITED_ALL){
		if(energy >= 0){
			return 0;
		}else{
			return INT_MAX;
		}
	}
	if(energy <= 0){
		return INT_MAX;
	}
	if(dp[curr][mask][energy] != -1){
		return dp[curr][mask][energy];
	}
	int ans = INT_MAX;
	for(auto x : graph[curr]){
		int dest = x[0];
		int dist = x[1];
		int ener = x[2];
		if(!((mask>>(dest-1))&1)){		
			int temp = dist + solve(dest, mask|(1<<(dest-1)), energy-ener);
			ans = min(ans, temp);
		}
	}
	return dp[curr][mask][energy] = ans;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int vertices, edges, energy, u, v, d, e;
	cin>>vertices>>edges>>energy;
	VISITED_ALL = (1<<edges)-1;
	for(int i = 0; i < edges; i++){
		cin>>u>>v>>d>>e;
		graph[u].push_back({v, d, e});
		graph[v].push_back({u, d, e});
	}
	memset(dp, -1, sizeof dp);
	int ans = solve(1, 1, energy);
	if(ans == INT_MAX){
		cout<<-1<<endl;
	}else{
		cout<<ans<<endl;
	}
	


	return 0;
}