#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005, M = 22;
vector<pair<int, int> > gr[N];

int depth[N] = {0};
int par[N][M];
int mn[N][M];
int mx[N][M];

void dfs(int current, int parent, int cost){
	par[current][0] = parent;
	if(cost != -1){
		mn[current][0] = mx[current][0] = cost;
	}
	for(int j = 1; j < M; j++){
		par[current][j] = par[par[current][j-1]][j-1];
		mn[current][j] = min(mn[current][j-1], mn[par[current][j-1]][j-1]);
		mx[current][j] = max(mx[current][j-1], mx[par[current][j-1]][j-1]);
	}
	for(auto x : gr[current]){
		auto child = x.first;
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

	int diff = depth[u]-depth[v];
	for(int i = M; i >= 0; i--){
		if((diff>>i)&1){
			u = par[u][i];
		}
	}
	if(u == v){
		return u;
	}

	for(int i = M; i >= 0; i--){
		if(par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

pair<int, int> querry(int a, int b){
	int mini = INT_MAX;
	int maxi = INT_MIN;
	int depth_a = depth[a];
	int depth_b = depth[b]; 
	for(int i = M-1; i >= 0; i--){
		if(depth_a + (1<<i) <= depth_b){
			mini = min(mini, mn[b][i]);
			maxi = max(maxi, mx[b][i]);
			depth_a += (1<<i);
		}
	}
	return make_pair(mini, maxi);
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int v, x, y, c;
	cin>>v;
	for(int i = 0; i < v-1; i++){
		cin>>x>>y>>c;
		gr[x].push_back(make_pair(y, c));
		gr[y].push_back(make_pair(x, c));

	}	
	dfs(1, 0, -1);
	int q;
	cin>>q;
	while(q--){
		cin>>x>>y;
		if(x == y){
			cout<<0<<" "<<0<<endl;
		}else{

			int LCA = lca(x, y);
			// cout<<LCA<<" "<<endl;	
			if(LCA == x){
				auto temp = querry(LCA, y);
				cout<<temp.first<<" "<<temp.second<<endl;
			}else if(LCA == y){
				auto temp = querry(LCA, x);
				cout<<temp.first<<" "<<temp.second<<endl;
			}else{
				auto p1 = querry(LCA, y);
				auto p2 = querry(LCA, x);
				if(p1.first <= p2.first){
					cout<<p1.first<<" ";
				}else{
					cout<<p2.first<<" ";
				}
				if(p1.second >= p2.second){
					cout<<p1.second<<endl;
				}else{
					cout<<p2.second<<endl;
				}
			}
		}
	}


	


	return 0;
}