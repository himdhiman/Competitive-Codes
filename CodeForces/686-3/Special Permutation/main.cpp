#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100002;
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
		for(int i = 1; i < n; i++){
			arr[i] = i+1;
		}
		arr[n] = 1;
		for(int i = 1; i <= n; i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;

	}

	


	return 0;
}