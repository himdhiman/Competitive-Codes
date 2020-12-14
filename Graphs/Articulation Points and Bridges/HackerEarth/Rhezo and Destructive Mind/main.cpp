#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 101;
vector<int> graph[N];
int tmr;
vector<int> artPoints;

int low[N] = {0}, disc[N] = {0};

void DFS(int curr, int par){
	low[curr] = disc[curr] = tmr++;
	int noChild = 0;
	for(auto x : graph[curr]){
		if(disc[x] == 0){
			DFS(x, curr);
			noChild++;
			low[curr] = min(low[curr], low[x]);
			if(par != 0 and low[x] >= disc[curr]){
				artPoints.push_back(curr);
			}
		}else if(x != par){
			low[curr] = min(low[curr], disc[x]);
		}
	}
	if(par == 0 and noChild > 2){
		artPoints.push_back(curr);
	}
	return;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int v, e;
	cin>>v>>e;
	for(int i = 0; i < e; i++){
		int x, y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	tmr = 1;
	DFS(1, 0);
	int q;
	cin>>q;
	for(int i = 0; i < q; i++){
		int n;
		cin>>n;
		if(find(artPoints.begin(), artPoints.end(), n) != artPoints.end()){
			cout<<"Satisfied "<<graph[n].size()<<endl;
		}else{
			cout<<"Not Satisfied"<<endl;
		}
	}


	


	return 0;
}