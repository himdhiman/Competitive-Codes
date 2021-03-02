#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

unordered_map<int, list<pair<int, int> > > graph;
vector<int> dist(100005);
set<pair<int, int> > s;
unordered_map<int, vector<int> > res;


void Dijkistra(int src){
	for(auto x : graph){
		dist[x.first] = LLONG_MAX;
	}
	dist[src] = 0;
	s.insert(make_pair(0, src));

	while(!s.empty()){
		auto pair = *(s.begin());
		s.erase(s.begin());
		int node = pair.second;
		int nodeDist = pair.first;

		for(auto x : graph[node]){
			if(nodeDist + x.second < dist[x.first]){
				auto f = s.find(make_pair(dist[x.first], x.first));
				if(f != s.end()){
					s.erase(f);
				}
                dist[x.first] = nodeDist + x.second;
				s.insert(make_pair(nodeDist + x.second, x.first));
			}
		}
	}
	// for(auto x : dist){
	// 	cout<<x.first<<" --> "<<x.second<<endl;
	// }
	return;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int v, q, r;
		cin>>v>>q>>r;
		graph.clear();
		dist.clear();
		s.clear();
		for(int i = 1; i < v; i++){
			int x, y, w;
			cin>>x>>y>>w;
			graph[x].push_back(make_pair(y, w));
			graph[y].push_back(make_pair(x, w));
		}
		int U, V;
		Dijkistra(2);
		for(int i = 0; i < q; i++){
			cin>>U>>V;
			if(res.find(U) == res.end()){
				Dijkistra(U);
				for(int i = 0; i <= v; i++){
					res[U].push_back(dist[i]);
				}
			}
			cout<<res[U][V];
		}
	}

	return 0;
}