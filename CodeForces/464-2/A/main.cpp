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

	int n, val;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>arr[i];
	}
	for(int i = 1; i <= n; i++){
		if(arr[arr[arr[i]]] == i){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";

	


	return 0;
}