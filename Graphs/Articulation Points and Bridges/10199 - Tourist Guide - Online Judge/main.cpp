#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<string> art_p;

void articulationPoints(string current, string parent, int tmr, unordered_map<string, list<string> > graph, unordered_map<string, int> &dis, unordered_map<string, int> &low){
	dis[current] = low[current] = tmr++;
	int no_child = 0;
	for(auto x : graph[current]){
		if(!dis[x]){
			articulationPoints(x, current, tmr, graph, dis, low);
			no_child++;
			low[current] = min(low[current], low[x]);
			if(parent != "aaa" and low[x] >= dis[current]){
				art_p.push_back(current);
			}
		}else if(x != parent){
			low[current] = min(low[current], dis[x]);
		}
	}
	if(parent == "aaa" and no_child >= 2){
		art_p.push_back(current);
	}


}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int v, e, cnt = 1;
	string s;
	cin>>v;
	while(v != 0){
		getline(cin, s);
		string current;
		unordered_map<string, list<string> > graph;
		list<string> l;
		for(int i = 0; i < v; i++){
			getline(cin, s);
			current = s;
			graph.insert(make_pair(s, l));
		}
		cin>>e;
		getline(cin, s);
		for(int i = 0; i < e; i++){
			getline(cin, s);
			s += " ";
			int start = 0;
			vector<string> inp;
			for(int i = 0; i < s.length(); i++){
				if(s[i] == ' '){
					inp.push_back(s.substr(start, (i-start)));
					start = i+1;
				}
			}
			graph[inp[0]].push_back(inp[1]);
			graph[inp[1]].push_back(inp[0]);
		}
		int N = 101;
		unordered_map<string, int> dis;
		unordered_map<string, int> low;
		for(auto x : graph){
			dis[x.first] = 0;
			low[x.first] = 0;
		}
		int tmr = 1;
		string par = "aaa";
		articulationPoints(current, par, tmr, graph, dis, low);
		cout<<"City map #"<<cnt<<": "<<art_p.size()<<" camera(s) found"<<endl;
		for(auto x : art_p){
			cout<<x<<endl;
		}
		cout<<endl;
		art_p.clear();
		cnt++;
		cin>>v;
	}


	return 0;
}