#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> g[N];
vector<int> gr[N];
vector<vector<int> > paths;
vector<int> visited(N, 0);
vector<int> temp;
vector<int> vstack;
map<int, char> components;
vector<int> funTime(N);

// Get path

void getPaths(int curr, int target){
	visited[curr] = 1;
	temp.push_back(curr);
	for(auto x : g[curr]){
		if(!visited[x]){
			getPaths(x, target);
			if(x == target){
				temp.push_back(x);
				paths.push_back(temp);
				temp.pop_back();
			}
		}
	}
	visited[curr] = 0;
	temp.pop_back();
}

// Get Stromgly Connected Compoonents

void getStack(int curr){
	visited[curr] = 1;
	for(auto x : g[curr]){
		if(!visited[x]){
			getStack(x);
		}
	}
	vstack.push_back(curr);
}

void getMap(int curr, char no){
	visited[curr] = 1;
	components.insert(make_pair(curr, no));
	for(auto x : gr[curr]){
		if(!visited[x]){
			getMap(x, no);
		}
	}
}


void GetComponents(int v){
	fill(visited.begin(), visited.end(), 0);
	for(int i = 1; i <= v; i++){
		if(!visited[i]){
			getStack(i);
		}
	}
	fill(visited.begin(), visited.end(), 0);
	char no = 'A';
	for(int i = vstack.size()-1; i >= 0; i--){
		if(!visited[vstack[i]]){
			getMap(vstack[i], no);
			no++;
		}
	}
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int edges, vertices, u, v, start, end;
	cin>>vertices>>edges>>start>>end;
	for(int i = 1; i <= vertices; i++){
		cin>>funTime[i];
	}
	for(int i = 0; i < edges; i++){
		cin>>u>>v;
		g[u].push_back(v);
		gr[v].push_back(u);
	}
	getPaths(start, end);
	GetComponents(vertices);
	int ans = 0;
	for(auto x : paths){
		int temp_ans = 0;
		set<char> s;
		for(auto y : x){
			s.insert(components[y]);
		}
		for(auto y : components){
			if(s.find(y.second) != s.end()){
				temp_ans += (funTime[y.first]);
			}
		}
		ans = max(ans, temp_ans);
	}
	cout<<ans;
	return 0;
}