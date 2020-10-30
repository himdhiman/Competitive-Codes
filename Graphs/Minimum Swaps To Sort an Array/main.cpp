#include<bits/stdc++.h>
#define int long long
using namespace std;

int dfs(vector<int> v, vector<bool> &visited, int src, int &cnt){
	visited[src] = true;
	if(visited[v[src]] == false){
		cnt++;
		dfs(v, visited, v[src], cnt);
	}
	return cnt;
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin>>v[i];
	}

	vector<bool> visited(n);
	for(int i = 0; i < n; i++){
		if(v[i] == i){
			visited[i] = true;
		}else{
			visited[i] = false;
		}
	}
	// for (int i = 0; i < n; ++i){
	// 	cout<<visited[i]<<" ";
	// }
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(visited[i] == false){
			int cnt = 0;
			ans += dfs(v, visited, i, cnt);
		}
	}

	cout<<ans;


	return 0;
}