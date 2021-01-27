#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int par[N];
int cnt[N];
int state[N];
vector<int> gr[N];

void dfs(int curr, int parent){
	par[curr] = parent;
	for(auto x : gr[curr]){
		if(x != parent){
			dfs(x, curr);
			cnt[curr] += (cnt[x]);
		}
	}
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, x, y, q;
	cin>>n>>q;
	for(int i = 0; i < n-1; i++){
		cin>>x>>y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}
	for(int i = 0; i < N; i++){
		cnt[i] = 1;
		state[i] = 1;
	}
	dfs(1, 0);
	// for(int i = 1; i < 6; i++){
	// 	cout<<cnt[i]<<" ";
	// }
	for(int i = 0; i < q; i++){
		cin>>x>>y;
		if(x == 1){
			int temp = par[y];
			int val = cnt[temp];
			if(state[temp] == 1){
				while(temp != 0){
					cnt[temp] -= val;
					temp = par[temp];
				}
				state[y] = 0;
			}else{
				while(temp != 0){
					cnt[temp] += val;
					temp = par[temp];
				}
				state[y] = 1;
			}
			// for(int i = 1; i < 3; i++){
			// 	cout<<cnt[i]<<" ";
			// }
			// cout<<endl;
			// for(int i = 1; i < 3; i++){
			// 	cout<<state[i]<<" ";
			// }
			// cout<<endl;
		}else{
			if(state[y] == 1){
				cout<<cnt[y]<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}


	


	return 0;
}