#include<bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<int> g[], vector<int> &stack, vector<int> &visited){
	visited[curr] = 1;
	for(auto x : g[curr]){
		if(!visited[x]){
			dfs(x, g, stack, visited);
		}
	}
	stack.push_back(curr);
}

void dfs2(int curr, vector<int> g[], vector<int> &visited){
	visited[curr] = 1;
	cout<<curr<<" ";
	for(auto x : g[curr]){
		if(!visited[x]){
			dfs2(x, g, visited);
		}
	}
}


void solve(vector<int> g[], vector<int> gr[], int n){
	vector<int> visited(n+1, 0);
	vector<int> stack;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i, g, stack, visited);
		}
	}
	fill(visited.begin(), visited.end(), 0);
	char component_name = 'A';
	for(int i = stack.size()-1; i >= 0; i--){
		int node = stack[i];
		if(!visited[node]){
			cout<<component_name<<" --> ";
			dfs2(node, gr, visited);
			cout<<endl;
			component_name++;
		}
	}

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, u, v;
	cin>>n;
	vector<int> g[n+1];
	vector<int> gr[n+1];
	for(int i = 0; i < n; i++){
		cin>>u>>v;
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	solve(g, gr, n);
}