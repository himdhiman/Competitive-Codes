#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1005, M = 11;
vector<int> gr[N];
int par[N][M];
int depth[N] = {0};

void dfs(int current, int parent){
	par[current][0] = parent;
	for(int j = 1; j < M; j++){
		par[current][j] = par[par[current][j-1]][j-1];
	}

	for(auto child : gr[current]){
		if(child != parent){
			depth[child] = depth[current] + 1;
			dfs(child, current);
		}
	}

}

int LCA(int u, int v){
	if(u == v){
		return u;
	}
	if(depth[v] > depth[u]){
		swap(u, v);
	}

	int diff = depth[u]-depth[v];

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

	int tc, n, num, val, q, x, y;
	cin>>tc;
	for(int t = 0; t < tc; t++){
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>num;
			for(int j = 0; j < num; j++){
				cin>>val;
				gr[i].push_back(val);
			}
		}
		dfs(1, 0);
		cin>>q;
		cout<<"Case "<<t+1<<":"<<endl;
		while(q--){
			cin>>x>>y;
			cout<<LCA(x, y)<<endl;
		}
		for(int i = 0; i < N; i++){
			gr[i].clear();
		}
		memset(par, 0, sizeof par);
		memset(depth, 0, sizeof depth);
	}

	


	return 0;
}