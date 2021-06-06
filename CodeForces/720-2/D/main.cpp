#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
vector<int> degree(N, 0);
vector<int> degreeMoreThantwo, degreeOne;

unordered_map<int, vector<int> > graph;

int solve(int n){

	return 0;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		fill(degree.begin(), degree.end(), 0);
		graph.clear();
		int vertices, u, v;
		cin>>vertices;
		for(int i = 0; i < v-1; i++){
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
			degree[u]++;
			degree[v]++;
		}
		for(int i = 1; i <= vertices; i++){
			if(degree[i] > 2){
				degreeMoreThantwo.push_back(i);
			}else if(degree[i] == 1){
				degreeOne.push_back(i);
			}
		}
		

	}

	


	return 0;
}