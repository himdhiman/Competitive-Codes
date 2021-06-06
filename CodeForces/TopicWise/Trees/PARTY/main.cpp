#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
vector<int> graph[N];

void dfs(int curr, int &depth, int dep){
	depth = max(depth, dep);
	for(auto x : graph[curr]){
		dfs(x, depth, dep+1);
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, v;
	vector<int> temp;
	cin>>n;
	for(int u = 1; u <= n; u++){
		cin>>v;
		if(v != -1){
			graph[v].push_back(u);
		}else{
			temp.push_back(u);
		}
	}
	// for(int i = 1; i <= n; i++){
	// 	cout<<i<<" --> ";
	// 	for(auto x : graph[i]){
	// 		cout<<x<<" ";
	// 	}
	// 	cout<<endl;
	// }

	int depth = 0;
	for(int i = 0; i < temp.size(); i++){
		dfs(temp[i], depth, 1);
	}
	// for(int i = 1; i <= n; i++){
	// 	if(!visited[i]){
	// 		dfs(i, depth, 1);
	// 	}
	// }
	cout<<depth<<endl;



	return 0;
}