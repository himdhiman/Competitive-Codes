#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){

	return 0;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int n, val;
		cin>>n;
		string s;
		cin>>s;
		vector<int> graph[n+1];
		for(int i = 2; i <= n; i++){
			cin>>val;
			graph[val].push_back(i);
			graph[i].push_back(val);
		}
		for(int i = 1; i <= n; i++){
			cout<<i<<" --> ";
			for(auto x : graph[i]){
				cout<<x<<" ";
			}
			cout<<endl;
		}

	}

	


	return 0;
}