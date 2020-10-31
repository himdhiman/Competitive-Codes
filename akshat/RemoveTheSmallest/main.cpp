#include<bits/stdc++.h>
#define int long long
using namespace std;





int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	vector<int> input(n, 0);
	int minimum = LLONG_MAX;
	for(int i = 0; i < n; i++){
		cin>>input[i];
		minimum = min(minimum, input[i]);
	}
	auto p = find(input.begin(), input.end(), minimum);
	input.erase(p);
	for(auto x : input){
		cout<<x<<" ";
	}
	return 0;
}