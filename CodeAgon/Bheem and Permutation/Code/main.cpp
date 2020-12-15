#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];

// int solve(int n){

// 	return 0;
// }



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		for(int i = 0; i < n; i++){
			if(i == k-1){
				cout<<n;
			}else if(i < k-1){
				cout<<i+1;
			}else{
				cout<<i;
			}
		}
		cout<<endl;
	}

	


	return 0;
}