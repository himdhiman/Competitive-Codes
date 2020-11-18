#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
vector<int> graph[N];
vector<int> visited(N, 0);

void DFS(int curr){
	visited[curr] = 1;
	for(auto x : graph[curr]){
		if(!visited[x]){
			DFS(x);
		}
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, m, k, u, v;
	cin>>n>>m>>k;
	for(int i = 0; i < m; i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			DFS(i);
			cnt++;
		}
	}
	if(cnt > k){
		cout<<-1;
		return 0;
	}
	cout<<m-n+k;


	return 0;
}