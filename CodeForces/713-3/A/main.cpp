#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];



int solve(int n){
	map<int, int> m;
	for(int i = 0; i < n; i++){
		m[arr[i]]++;
	}
	int element = -1;
	for(auto x : m){
		if(x.second == 1){
			element = x.first;
			break;
		}
	}
	for(int i = 0; i < n; i++){
		if(arr[i] == element){
			return i+1;
		}
	}

	return -1;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		cout<<solve(n)<<endl;;
		
	}


	return 0;
}