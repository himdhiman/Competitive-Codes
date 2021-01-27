#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
vector<int> gr[N];
int visited[N] = {0};
int V[N], P[N];

void DFS(int curr, int &total, int &mn){
	visited[curr] = 1;
	total += P[curr];
	if(V[curr] != -1){
		mn = min(mn, V[curr]);
	}
	for(auto x : gr[curr]){
		if(!visited[x]){
			DFS(x, total, mn);
		}
	}
	return;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int v, e;
	cin>>v>>e;
	for(int i = 1; i <= v; i++){
		cin>>V[i];
	}
	for(int i = 1; i <= v; i++){
		cin>>P[i];
	}
	int x, y;
	for(int i = 1; i <= e; i++){
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	int ans = 0;
	for(int i = 1; i <= v; i++){
		if(visited[i] == 0){
			int total = 0;
			int mn = INT_MAX;
			DFS(i, total, mn); 
			if(mn == INT_MAX){
				cout<<"impossible";
				return 0;
			}
			ans += (total*mn);
		}
	}
	cout<<ans;
	


	return 0;
}