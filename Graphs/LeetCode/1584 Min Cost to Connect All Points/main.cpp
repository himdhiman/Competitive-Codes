#include<bits/stdc++.h>
// #define int long long
using namespace std;

class DSU{
public:
	int * parent;
	int * RanK;

	DSU(int v){
		parent = new int[v];
		RanK = new int[v];

		for(int i = 0; i < v; i++){
			parent[i] = i;
			RanK[i] = 1;
		}
	}

	int find(int x){
		if(parent[x] == x){
			return x;
		}
		return parent[x] = find(parent[x]);
	}

	bool unite(int x, int y){
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
			return false;
		}
		return true;
	}
};


int minCostConnectPoints(vector<vector<int>>& points) {
	vector<vector<int> > Graph;
	int n = points.size();
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int w = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
			Graph.push_back({w, i, j});
		}
	}
	sort(Graph.begin(), Graph.end());
	DSU d(n);
	int ans = 0;
	for(int i = 0; i < Graph.size(); i++){
		int u = Graph[i][1];
		int v = Graph[i][2];
		int w = Graph[i][0];
		if(d.unite(u, v) == false){
			ans += w;
		}
	}
	return ans;
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n, x, y;
	cin>>n;
	vector<vector<int> > points;
	for(int i = 0; i < n; i++){
		cin>>x>>y;
		points.push_back({x, y});
	} 

	int ans = minCostConnectPoints(points);
	cout<<ans;



	return 0;
}