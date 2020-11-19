#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve(int * arr, int n){
	if(n == 0){
		return 1;
	}

	int ans = max((arr[n-1]+solve(arr, n-1))*solve(arr, n-1), (arr[n-1]+solve(arr, n-1))*solve(arr, n-1));
	return ans;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	cout<<solve(arr, n)<<endl;

	


	return 0;
}