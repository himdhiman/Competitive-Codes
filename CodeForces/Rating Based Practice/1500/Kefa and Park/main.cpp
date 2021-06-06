#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
unordered_map<int, vector<int> > graph;
vector<int> visited(N, 0);

int dfs(int curr, int m, int currVal){
	visited[curr] = 1;
	int temp = currVal;
	if(arr[curr] == 0){
		temp = 0;
	}else{
		temp++;
	}
	// cout<<curr<<" "<<temp<<endl;
	if(temp > m){
		return 0;
	}
	if(graph[curr].size() == 1 and curr != 1){
		return 1;
	}
	int ans = 0;
	for(auto x : graph[curr]){
		if(!visited[x]){
			ans += dfs(x, m, temp);
		}
	}
	visited[curr] = 0;
	return ans;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, m, u, v;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	for(int i = 1; i < n; i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);		
	}
	int currVal = 0, root = 1;
	cout<<dfs(root, m, currVal);

	


	return 0;
}