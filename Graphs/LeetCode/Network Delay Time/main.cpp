#include<bits/stdc++.h>
// #define int long long
using namespace std;

int solve(vector<vector<int> > input, int n, int src){
	unordered_map<int, list<pair<int, int> > > m;
	unordered_map<int, int> distance;
	for(auto x : input){
		m[x[0]].push_back(make_pair(x[1], x[2]));
		distance[x[0]] = INT_MAX;
		distance[x[1]] = INT_MAX;
	}
	// for(auto x : distance){
	// 	cout<<x.first<<" --> "<<x.second<<endl;
	// }
	set<pair<int, int> > s;
	distance[src] = 0;
	s.insert(make_pair(0, src));

	while(!s.empty()){
		auto curr = *(s.begin());
		s.erase(s.begin());

		int node = curr.second;
		int nodeDist = curr.first;

		for(auto childPair : m[node]){
			if(distance[childPair.first] > nodeDist + childPair.second){
				auto f = s.find(make_pair(distance[childPair.first], childPair.first));
				if(f != s.end()){
					s.erase(f);
				}
				distance[childPair.first] = nodeDist + childPair.second;
				s.insert(make_pair(distance[childPair.first], childPair.first));
			}
		}
	}
	for(auto x : distance){
		cout<<x.first<<" --> "<<x.second<<endl;
	}
	return 0;
}



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	vector<vector<int> > input;
	for(int i = 0; i < n; i++){
		int u, v, w;
		cin>>u>>v>>w;
		input.push_back({u, v, w});
	}
	int src;
	cin>>src;

	solve(input, n, src);


	return 0;
}