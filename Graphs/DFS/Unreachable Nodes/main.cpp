#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int V, E;
vector<int> gr[N];
int visited[N] = {0};

void DFS(int curr){
	visited[curr] = 1;
	for(auto x : gr[curr]){
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
	cin>>V>>E;
	int x, y;
	for(int i = 1; i <= E; i++){
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	int start;
	cin>>start;
	DFS(start);
	int cnt = 0;
	for(int i = 1; i <= V; i++){
		if(visited[i] == 0){
			cnt++;
		}
	}
	cout<<cnt;

	return 0;
}