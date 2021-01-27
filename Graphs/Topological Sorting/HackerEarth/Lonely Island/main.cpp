#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005;
int outdegree[N] = {0}, indegree[N] = {0}, visited[N] = {0};
vector<int> gr[N];
int ans = 0;


void dfs(int curr){
	visited[curr] = 1;
	if(outdegree[curr] == 0){
		if(ans < indegree[curr]){
			ans = indegree[curr];
		}

	}
	for(auto x : gr[curr]){
		if(!visited[x]){
			dfs(x);
		}
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif 

	int v, e, initial, x, y;
	cin>>v>>e>>initial;
	for(int i = 0; i < e; i++){
		cin>>x>>y;
		outdegree[x]++;
		indegree[y]++;
		gr[x].push_back(y);
	}
	dfs(initial);
	vector<int> res;
	for(int i = 1; i < N; i++){
		if(indegree[i] == ans){
			res.push_back(i);
		}
	}
	for(auto x : res){
		cout<<x<<" ";
	}


	return 0;
}