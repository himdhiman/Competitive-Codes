#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
vector<int> low(N, 0), dis(N, 0);
set<int> art_p;
int tmr;

void dfs(int curr, int par, vector<int> graph[]){
	dis[curr] = low[curr] = tmr++;
	int no_child = 0;
	for(auto x : graph[curr]){
		if(dis[x] == 0){
			dfs(x, curr, graph);
			no_child++;
			low[curr] = min(low[x], low[curr]);
			if(par != 0 and low[x] >= dis[curr]){
				art_p.insert(curr);
			}
		}else if(x != par){
			low[curr] = min(dis[x], low[curr]);
		}
	}
	if(par == 0 and no_child >= 2){
		art_p.insert(curr);
	}

}

int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int v, e, x, y;
	cin>>v>>e;
	while(v != 0 and e != 0) {
		vector<int> graph[v+1];
		for(int i = 0; i < e; i++){
			cin>>x>>y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		tmr = 1;
		dfs(1, 0, graph);
		cout<<art_p.size()<<endl;
		art_p.clear();
		fill(low.begin(),low.end(), 0);
		fill(dis.begin(),dis.end(), 0);
		cin>>v>>e;
	}
	return 0;
}