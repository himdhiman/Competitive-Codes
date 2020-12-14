#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int parent[N];

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
		if(p1 > p2){
			parent[p2] = p1;
		}else{
			parent[p1] = p2;
		}
	}
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, e;
	cin>>n>>e;
	for(int i = 1; i <= n; i++){
		parent[i] = i;
	}
	int u, v;
	for(int i = 0; i < e; i++){
		cin>>u>>v;
		unite(u, v);
	}
	for(int i = 1; i <= n; i++){
		find(i);
	}
	int q;
	cin>>q;
	while(q--){
		cin>>u>>v;
		int x = find(u);
		int y = find(v);
		if(x == y){
			cout<<"TIE"<<endl;
		}else if(x > y){
			cout<<u<<endl;
		}else{
			cout<<v<<endl;
		}
	}
	return 0;
}