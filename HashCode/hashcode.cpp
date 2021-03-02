#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// unordered_map<int, list<pair<int, pair<int, int> > > graph;
unordered_map<int, list<vector<int> > > graph;

vector<int> path[1000];

map<int, vector<string> > Indegree;


unordered_map<string, int> mapping;




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("f.txt", "r", stdin);
	freopen("output_f.txt", "w", stdout);
#endif 

	
	int D, I, S, V, F;
	cin>>D>>I>>S>>V>>F;

	int ref = 0;
	for(int i = 0; i < S; i++){
		int x, y, l;
		string s;
		cin>>x>>y>>s>>l;
		if(mapping.find(s) == mapping.end()){
			mapping[s] = ref;
			ref++;
		}
		// graph[x].push_back(make_pair(y, make_pair(l, mapping[s])));
		Indegree[y].push_back(s);
		vector<int> temp;
		temp.push_back(y);
		temp.push_back(l);
		temp.push_back(mapping[s]);

		graph[x].push_back(temp);
	}
	for(int i = 0; i < V; i++){
		int p;
		string s;
		cin>>p;
		for(int j = 0; j < p; j++){
			cin>>s;
			path[j].push_back(mapping[s]);
		}
	}

	// for(auto x : Indegree){
	// 	cout<<x.first<<" --> ";
	// 	for(auto y : x.second){
	// 		cout<<y<<" ";
	// 	}
	// 	cout<<endl;
	// }


	// for(auto x : Indegree){
	// 	cout<<x.first<<" --> ";
	// 	for(auto y : x.second){
	// 		cout<<y<<" ";
	// 	}
	// 	cout<<endl;
	// }	


	// Output
	int count = 0;
	cout<<I<<endl;
	for(auto x:Indegree){
		cout<<x.first<<endl;
		cout<<x.second.size()<<endl;
		for(auto y:x.second){

			cout<<y<<" "<<2<<endl;

		}

	}


	return 0;
}