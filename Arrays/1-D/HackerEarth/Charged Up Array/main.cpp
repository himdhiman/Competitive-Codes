#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){
	if(n >= 64){
		return 0;
	}
	int ans = 0;	
	int k = (1ll<<(n-1));
	for(int i = 0; i < n; i++){
		if(arr[i] >= k){
			ans = (ans%MOD + arr[i]%MOD)%MOD;
		}
	}
	return ans%MOD;
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
		cout<<solve(n)<<endl;
	}


	


	return 0;
}