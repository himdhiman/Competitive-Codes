#include<bits/stdc++.h>
#define int long long
using namespace std;



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input2.txt", "r", stdin);
		freopen("output2.txt", "w", stdout);
	#endif 

	int n;
	cin>>n;

	vector<int> inp(n);
	for(int i = 0; i < n; i++){
		cin>>inp[i];
	}

	int ans = INT_MAX;
	set<int> s;
	for(int i = 0; i < n; i++){
		if(s.find(inp[i]) == s.end()){
			s.insert(inp[i]);
			int temp = 0;
			for(int j = 0; j < n; j++){
				if(inp[j] != inp[i]){
					temp += (inp[j]);
				}
			}
			ans = min(ans, temp);
		}
	}
	cout<<ans;



	return 0;
}