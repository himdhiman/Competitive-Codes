#include<bits/stdc++.h>
using namespace std;

int main() {

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	unordered_map<int, int> HX, HY;

	int n;
	cin>>n;

	for(int i = 0; i < n; i++){
		int x, y;
		cin>>x>>y;
		HX[x]++;
		HY[y]++;
	}
	int ans = 0;
	for(auto x : HX){
		for(auto y : HY){
			ans += (x.second-1)*(y.second-1);
		}
	}
	cout<<ans;
	return 0;
}