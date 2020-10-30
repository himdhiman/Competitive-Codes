#include<bits/stdc++.h>
using namespace std;

const int N = 10000;

vector<int> graph[N];
int par[N];
int dep[N];

void dfs(int child, int parent){
	par[child] = parent;
	for(auto x : graph[child]){
		if(x != parent){
			dep[x] = dep[child] + 1;
			dfs(x, child);
		}
	}
}


int LCA(int u, int v){
	if(dep[u] < dep[v]){
		swap(u, v);
	}
	while(dep[u] != dep[v]){
		u = par[u];
	}
	while(u != v){
		u = par[u];
		v = par[v];
	}
	return u;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, u, v;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1, 0);
	cout<<LCA(7, 9);
}