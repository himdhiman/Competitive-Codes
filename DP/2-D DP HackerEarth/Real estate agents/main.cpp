#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
int c[N], l[N], r[N];
int n, m, k;
unordered_map<int, vector<int> > ass_agent;
unordered_map<int, int> ag_cost;

int solve(int i, int j, vector<int> visited){
	if(i == 0 || j == 0){
		return 0;
	}
	if(ass_agent.find(i) == ass_agent.end()){
		return solve(i-1, j, visited);
	}
	int ans1 = INT_MAX, ans2 = INT_MAX;
	ans1 = solve(i-1, j, visited);
	int mn = INT_MAX;
	if(visited[i] == 1){
		ans2 = solve(i-1, j-1, visited);
	}else{
		int ag = -1;
		for(auto x : ass_agent[i]){
			if(ag_cost[x] < mn){
				ag = x;
				mn = ag_cost[x];
			}
		}
		for(int x = l[ag]; x <= r[ag]; x++){
			visited[x] = 1;
		}
	}

	ans2 = mn + solve(i-1, j-1, visited);

	return min(ans1, ans2);
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	cin>>n>>m>>k;
	for(int i = 1; i <= m; i++){
		cin>>l[i]>>r[i]>>c[i];
		ag_cost[i] = c[i];
		for(int j = l[i]; j <= r[i]; j++){
			ass_agent[j].push_back(i);
		}
	}
	vector<int> visited(n+1, 0);
	cout<<solve(n, k, visited);

	return 0;
}