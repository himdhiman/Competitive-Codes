#include <bits/stdc++.h>
using namespace std;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	int v, e, s, d;
	cin>>v>>e;
	vector<int> indegree(v+1, 0);
	unordered_map<int , list<int> > AdjList;
	for(int i = 0; i < e; i++){
		cin>>s>>d;
		indegree[s]++;
		indegree[d]++;
		AdjList[s].push_back(d);
		AdjList[d].push_back(s);
	}
	int node = 0;
	int maximum = 0;
	for(int i = 1; i <= v; i++){
		if(indegree[i] > maximum){
			maximum = indegree[i];
			node = i;
		}
	}
	vector<int> res;
	while(res.size() == 0){
		for(int i = 1; i <= v; i++){
			if(indegree[i] == maximum && i != node){
				res.push_back(i);
			}
		}
		maximum--;
	}
	vector<vector<int> > out;
	for(int i = 0; i < res.size(); i++){
		if(node < res[i]){
			out.push_back({node, res[i]});
		}else{
			out.push_back({res[i], node});
		}
	}
	out.erase(unique(out.begin(), out.end()), out.end());
	for(auto x : out){
		for(auto y : x){
			cout<<y<<" ";
		}
		cout<<endl;
	}
	return 0;
}