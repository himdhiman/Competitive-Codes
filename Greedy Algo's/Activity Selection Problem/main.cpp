#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, s, e;
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >p;
	cin>>n;
	vector<int> st(n, 0);
	vector<int> ed(n, 0);
	for(int i = 0; i < n; i++){
		cin>>st[i];
	}
	for(int i = 0; i < n; i++){
		cin>>ed[i];
	}
	for(int i = 0; i < n; i++){
		p.push({ed[i], st[i]});
	}
	vector<pair<int, int> > result;
	auto t = p.top();
	int start = t.second;
	int end = t.first;
	result.push_back({start, end});
	p.pop();
	while(!p.empty()){
		auto curr = p.top();
		if(curr.second >= end){
			start = curr.second;
			end = curr.first;
			result.push_back({start, end});
		}
		p.pop();
	}
	for(auto x : result){
		cout<<x.first<<" "<<x.second<<endl;
	}
	


	return 0;
}