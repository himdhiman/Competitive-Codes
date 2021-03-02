#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
vector<pair<int, int> > gr[N];
int visited[N] = {0};
int dp[100][100];

void solve(int curr, int des, int &ans, int &temp){
	visited[curr] = 1;
	if(curr == des){
		ans = min(ans, temp);
		visited[des] = 0;
		return;
	}

	for(auto x : gr[curr]){
		for(auto y : gr[x.first]){
			if(visited[y.first] == 0){
				temp = temp + (x.second + y.second)*(x.second + y.second);
				solve(y.first, des, ans, temp);
				temp = temp - (x.second + y.second)*(x.second + y.second);
			}
		}
	}
	visited[curr] = 0;
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int v, e;
	cin>>v>>e;
	for(int i = 0; i < e; i++){
		int x, y, w;
		cin>>x>>y>>w;
		gr[x].push_back(make_pair(y, w));
		gr[y].push_back(make_pair(x, w));
	}
	cout<<0<<" ";
	// vec.push_back(1);
	for(int i = 2; i <= v; i++){
		memset(visited, 0, sizeof visited);
		memset(dp, 0, sizeof dp);
		int ans = INT_MAX;
		int temp = 0;
		solve(1, i, ans, temp);
		if(ans == INT_MAX){
			cout<<-1<<" ";
		}else{
			cout<<ans<<" ";
		}
	}
	return 0;
}