#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
int arr[N];
int k;


int solve(int i){
	if(i < 0 or i >= k){
		return 0;
	}
	if(i == k-1){
		return arr[i];
	}
	return arr[i] + min(solve(i-1), solve(i+2));
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	cin>>k;
	for(int i = 0; i < k; i++){
		cin>>arr[k];
	}
	cout<<solve(0);
	


	return 0;
}