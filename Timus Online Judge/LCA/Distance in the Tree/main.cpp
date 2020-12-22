#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005, M = 22;
int dist[N] = {0};
int depth[N] = {0};
vector<pair<int, int> > gr[N];
int par[N][M];

void dfs(int current, int parent, int dis){
	if(parent != -1){
		par[current][0] = parent;
	}
	for(int j = 1; j < M; j++){
		par[current][j] = par[par[current][j-1]][j-1];
	}
	if(dis != -1){
		dist[current] = dist[parent] + dis;
	}
	for(auto x : gr[current]){
		int child = x.first;
		if(child != parent){
			depth[child] = depth[current]+1;
			dfs(child, current, x.second);
		}
	}
	return;
}

int lca(int u, int v){
	if(u == v){
		return u;
	}
	if(depth[v] > depth[u]){
		swap(u, v);
	}
	int diff = depth[u] - depth[v];

	for(int i = M-1; i >= 0; i--){
		if((diff>>i)&1){
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



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, x, y, c;
	cin>>n;
	for(int i = 0; i < n-1; i++){
		cin>>x>>y>>c;
		gr[x].push_back({y, c});
		gr[y].push_back({x, c});
	}
	dfs(0, -1, -1);
	// for(int i = 0; i < n; i++){
	// 	cout<<dist[i]<<" ";
	// }
	int q;
	cin>>q;
	while(q--){
		cin>>x>>y;
		if(x == y){
			cout<<0<<endl;
		}else{
			int LCA = lca(x, y);
			cout<<LCA<<" ";
			if(LCA == x){
				cout<<dist[y]-dist[x]<<endl;
			}else if(LCA == y){
				cout<<dist[x]-dist[y]<<endl;
			}else{
				cout<<(dist[y]-dist[LCA])+(dist[x]-dist[LCA])<<endl;
			}
		}
	}
	// cout<<lca(2, 3);

	


	return 0;
}