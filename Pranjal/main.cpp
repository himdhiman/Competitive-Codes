#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include <climits>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, root;
	cin>>n;
	cin>>root;
	unordered_map<int, list<pair<int, int> > > AdjList;
	for(int i = 0; i < n; i++){
		int u, v, c;
		cin>>u>>v>>c;
		AdjList[u].push_back(make_pair(v, c));
	}
	int ans = 0;
	for(auto x : AdjList[root]){
		ans += x.second;
	}
	cout<<ans;
}