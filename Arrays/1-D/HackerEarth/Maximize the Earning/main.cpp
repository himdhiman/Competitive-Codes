#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10001;
int arr[N];

int solve(int n, int r){
	int mx = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] > mx){
			ans += r;
			mx = arr[i];
		}
	}
	return ans;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n, r;
		cin>>n>>r;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		cout<<solve(n, r)<<endl;

	}

	


	return 0;
}