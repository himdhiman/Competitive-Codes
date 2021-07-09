#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];

unordered_map<int, vector<int> > graph;
vector<int> visited(2005, 0);

void dfs(int curr, int &ans){
	visited[curr] = 1;
	for(auto x : graph[curr]){
		if(!visited[x]){
			ans++;
			dfs(x, ans);
		}
	}
}

void solve(){
	int v, e, x, y;
	cin>>v>>e;
	for(int i = 0; i < e; i++){
		cin>>x>>y;
		graph[x].push_back(y);
	}
	int res = 0;
	for(int i = 1; i <= v; i++){
		fill(visited.begin(), visited.end(), 0);
		int ans = 0;
		dfs(i, ans);
		res += (ans+1);
	}
	cout<<res<<endl;
	return;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	t = 1;
	// cin>>t;
	while(t--) solve();

	


	return 0;
}