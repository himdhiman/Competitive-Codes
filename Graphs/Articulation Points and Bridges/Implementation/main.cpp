#include<bits/stdc++.h>

using namespace std;

const int N = 100005;

vector<int> graph[N];
int disc[N] = {0}, low[N] = {0}, tme;
vector<int> art_p;
vector<pair<int, int> > brid;


void dfs(int curr, int par){
	disc[curr] = low[curr] = tme++;
	int no_child = 0;
	for(auto child : graph[curr]){
		if(disc[child] == 0){
			dfs(child, curr);
			no_child++;
			low[curr] = min(low[curr], low[child]);
			if(par != 0 and low[child] >= disc[curr]){
				art_p.push_back(curr);
			}
			if(low[child] > disc[curr]){
				brid.push_back({curr, child});
			}
		}else if(child != par){
			low[curr] = min(low[curr], disc[child]);
		}
	}
	if(par == 0 and no_child >= 2){
		art_p.push_back(curr);
	}
}



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int v, e;
	cin>>e>>v;

	for(int i = 0; i < e; i++){
		int x, y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}	
	tme = 1;
	dfs(1, 0);

	for(auto x : brid) cout<<x.first<<" "<<x.second<<endl;


	return 0;
}