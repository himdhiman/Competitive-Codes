#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
int n, p;
vector<int> graph[N];
vector<int> visited(N, 0);
set<int> allElements;
vector<int> path;
vector<int> c(N, 0);

void DFS(int s){
	visited[s] = 1;
	allElements.insert(s);
	for(auto x : graph[s]){
		if(!visited[x]){
			DFS(x);
		}
	}
}

void getPath(int start, int end){
	visited[start] = 1;
	path.push_back(start);
	for(auto x : graph[start]){
		if(!visited[x]){
			getPath(x, end);
			if(x == end){
				path.push_back(x);
				for(auto x : path){
					allElements.erase(allElements.find(x));
				}
				return;
			}
		}
	}
	path.pop_back();

}


vector<int> getVertices(int s, int v){
	fill(visited.begin(), visited.end(), 0);
	DFS(1);
	fill(visited.begin(), visited.end(), 0);
	getPath(1, 5);
	vector<int> res;
	for(auto x : allElements){
		res.push_back(x);
	}
	return res;
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int val;
		cin>>n>>p;
		for(int i = 2; i <= n; i++){
			cin>>val;
			graph[val].push_back(i);
		}
		for(int i = 1; i <= n; i++){
			cin>>c[i];
		}
		// vector<int> setU = getVertices(1, 6);
		// for(auto x : setU){
		// 	cout<<x<<" ";	
		// }

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				vector<int> setU = getVertices(j, i);
				for(auto x : setU){
					
				}
			}
		}
	}


	


	return 0;
}