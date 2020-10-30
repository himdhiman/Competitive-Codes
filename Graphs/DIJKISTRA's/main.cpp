#include<bits/stdc++.h>
#define int long long
using namespace std;

unordered_map<int, list<pair<int, int> > > graph;
unordered_map<int, int> dist;
set<pair<int, int> > s;

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
	for(auto x : dist){
		cout<<x.first<<" --> "<<x.second<<endl;
	}
	return;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int e;
	cin>>e;
	for(int i = 0; i < e; i++){
		int x, y, c;
		cin>>x>>y>>c;
		graph[x].push_back(make_pair(y, c));
		graph[y].push_back(make_pair(x, c));
	}
	Dijkistra(1);


	return 0;
}