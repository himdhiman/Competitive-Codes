#include<bits/stdc++.h>
using namespace std;

const int N = 100005, M = 22;

vector<int> graph[N];
int par[N][M], dep[N];

void dfs(int current, int parent){
	par[current][0] = parent;
	for(int j = 1; j < M; j++){
		par[current][j] = par[par[current][j-1]][j-1];
	}
	for(auto child : graph[current]){
		if(child != parent){
			dep[child] = dep[current] + 1;
			dfs(child, current);
		}
	}
}

int getLCA(int u, int v){
	if(u == v){
		return u;
	}

	if(dep[u] < dep[v]){
		swap(u, v);
	}

	int diff = dep[u] - dep[v];

	for(int i = M-1; i >= 0; i--){
		if((diff >> i) & 1){
			u = par[u][i];
		}
	}

	if(u == v){
		return u;
	}

	for(int i = M-1; i >= 0; i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}

	return par[u][0];
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
	cout<<getLCA(5, 3)<<endl;
	cout<<getLCA(7, 9)<<endl;

}