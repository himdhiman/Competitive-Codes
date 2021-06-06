#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];


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
		if(is_sorted(arr, arr+n)){
			cout<<0<<endl;
		}else if(arr[0] == 1 || arr[n-1] == n){
			cout<<1<<endl;
		}else if(arr[0] == n and arr[n-1] == 1){
			cout<<3<<endl;
		}else{
			cout<<2<<endl;
		}
	}

	


	return 0;
}