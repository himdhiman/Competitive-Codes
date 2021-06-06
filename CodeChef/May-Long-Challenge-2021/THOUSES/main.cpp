#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 300005;
unordered_map<int, vector<int> > graph;
vector<int> children(N, 0);
vector<int> val(N);
vector<int> visited(N, 0);

int dfs(int node, int parent){
	children[node] = 1;
	for(auto x : graph[node]){
		if(x != parent){
			children[node] += dfs(x, node);
		}
	}
	return children[node];
}

int bfs(int node){
	visited[node] = 1;
	int ans = val[node]%MOD;
	queue<int> q;
	priority_queue<pair<int, int> > pq;
	q.push(node);
	while(!q.empty()){
		int curr = q.front();
		int parVal = val[curr]%MOD;
		q.pop();
		for(auto x : graph[curr]){
			if(visited[x] == 0){
				pq.push({children[x], x});
				visited[x] = 1;
			}
		}
		int cnt = 1;
		while(!pq.empty()){
			auto pr = pq.top();
			pq.pop();
			val[pr.second] = ((cnt%MOD)*(parVal%MOD))%MOD;
			ans = (ans%MOD + val[pr.second]%MOD)%MOD;
			cnt++;
			q.push(pr.second); 
		}
	}
	return (ans%MOD);
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
		fill(children.begin(), children.end(), 0);
		fill(visited.begin(), visited.end(), 0);
		int n, x, u, v;
		cin>>n>>x;
		for(int i = 0; i < n-1; i++){
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		dfs(1, 0);
		val[1] = x%MOD;
		cout<<bfs(1)<<endl;
	}
	return 0;
}