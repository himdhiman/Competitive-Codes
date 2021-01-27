#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

vector<int> s;
const int N = 200005;
int cost[N] = {0};
vector<int> gr[N];



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input2.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif 

	int v, e, x, y;
	cin>>v>>e;
	for(int i = 1; i <= v; i++){
		cin>>cost[i];
	}
	for(int i = 0; i < e; i++){
		cin>>x>>y;
		gr[x].push_back(y);
	}

	vector<int> hi(v + 1, INT_MIN);
	int ans = INT_MIN;
	for (int i = v; i >= 1; --i) {
	    for (int x : gr[i]){
	    	hi[i] = max(hi[i], hi[x]);
	    }
	    ans = max(ans, hi[i] - cost[i]);
	    hi[i] = max(hi[i], cost[i]);		
	 }
	cout << ans;


	


	


	return 0;
}