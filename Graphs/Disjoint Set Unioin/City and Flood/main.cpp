#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int parent[N];
int RanK[N];

int find(int x){
	if(parent[x] == x){
		return x;
	}
	return parent[x] = find(parent[x]);
}

void unite(int x, int y){
	int p1 = find(x);
	int p2 = find(y);

	if(p1 != p2){
		if(RanK[p1] < RanK[p2]){
			parent[p1] = p2;
			RanK[p2] += RanK[p1];
		}else{
			parent[p2] = p1;
			RanK[p1] += RanK[p2];
		}
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, e;
	cin>>n;
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		RanK[i] = 1;
	}
	cin>>e;
	int u, v;
	while(e--){
		cin>>u>>v;
		unite(u, v);
	}
	for(int i = 1; i <= n; i++){
		find(i);
	}
	set<int> s;
	for(int i = 1; i <= n; i++){
		s.insert(parent[i]);
	}
	cout<<s.size();

	return 0;
}