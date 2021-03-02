#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(int n){
	vector<vector<int> > v(n);
	v[0].push_back(arr[0]);
	
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[j] < arr[i] and v[j].size()+1 > v[i].size()){
				v[i] = v[j];
			}
		}
		v[i].push_back(arr[i]);
	}
	vector<int> max = v[0];
	for(auto x : v){
		if(x.size() > max.size()){
			max = x;
		}
	}

	for(auto x : max){
		cout<<x<<" ";
	}
	return;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	solve(n);

	


	return 0;
}