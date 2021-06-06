#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

map<string, vector<string> > m;

// unordered_map<string, vector<string> > graph;

int solve(string s, int k){
	if(s.length() == k){
		return 1;
	}
	string curr = string(1, s[0]);
	int ans = 0;
	for(auto x : m[curr]){
		ans += solve(x + s.substr(1, s.length()-1), k);
	}
	return ans;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int k, n;
	cin>>k>>n;
	string a, b;
	for(int i = 0; i < n; i++){
		cin>>a>>b;
		m[b].push_back(a);
	}
	// for(auto x : m){
	// 	cout<<x.first<<" --> ";
	// 	for(auto y : x.second){
	// 		cout<<y<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// queue<string> q;
	// q.push("a");
	// int cnt = 0;
	// while(!q.empty()){
	// 	auto curr = q.front();
	// 	q.pop();
	// 	string first = curr[0];
	// 	for(auto x : m[first]){
	// 		q.push(x + curr.substr(1, curr.length()-1));
	// 	}

	// }
	string curr = "a";
	cout<<solve(curr, k)<<endl;


	


	return 0;
}