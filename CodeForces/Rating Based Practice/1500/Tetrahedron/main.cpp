#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000000;
unordered_map<char, vector<char> > graph;
int dp[4][N];
vector<char> v;

int dfs(char curr, int n){
	if(n == 0){
		if(curr == 'D'){
			for(auto x : v){
				cout<<x<<" ";
			}
			cout<<endl;
			return 1;
		}
		return 0;
	}
	if(dp[curr-'A'][n] != -1){
		return dp[curr-'A'][n];
	}
	int ans = 0;
	for(auto x : graph[curr]){
		v.push_back(x);
		ans = ((ans%MOD) +  (dfs(x, n-1)%MOD))%MOD;
		v.pop_back();
	}
	return dp[curr-'A'][n] = ans%MOD;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	graph['A'] = {'B', 'C', 'D'};
	graph['B'] = {'A', 'C', 'D'};
	graph['C'] = {'A', 'B', 'D'};
	graph['D'] = {'A', 'B', 'C'};
	int n;
	cin>>n;
	v.push_back('D');
	memset(dp, -1, sizeof dp);

	cout<<dfs('D', n);

	


	return 0;
}