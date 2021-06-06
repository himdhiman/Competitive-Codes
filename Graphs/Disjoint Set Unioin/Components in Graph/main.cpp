#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 15001;
int parent[N];

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int a, int b){
    int pa = find(a);
    int pb = find(b);
    
    if(pa != pb){
    	if(pa < pb){
    		parent[pb] = parent[pa];
    	}else{
    		parent[pa] = parent[pb];
    	}
    }
    return;
}


vector<int> componentsInGraph(vector<vector<int>> gb) {
    int start = INT_MAX, end = INT_MIN;
    for(auto x : gb){
        start = min(start, min(x[0], x[1]));
        end = max(end, max(x[0], x[1]));
    }
    for(int i = start; i <= end; i++){
        parent[i] = i;
    }
    for(auto x : gb){
        unite(x[0], x[1]);
    }
    for(int i = start; i <= end; i++){
        find(i);
    }
    unordered_map<int, int> m;
    for(int i = start; i <= end; i++){
        m[parent[i]]++;
    }
    vector<int> res(2);
    res[0] = INT_MAX;
    res[1] = INT_MIN;
    for(auto x : m){
    	if(x.second > 1){
        	res[0] = min(res[0], x.second);
    	}
        res[1] = max(res[1], x.second);        
    }
    return res;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	vector<vector<int> > edges;
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		int u, v;
		cin>>u>>v;
		edges.push_back({u, v});
	}
	vector<int> res = componentsInGraph(edges);
	cout<<res[0]<<" "<<res[1];


	return 0;
}