#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int i, int n){
	if(i == n-1){
		return arr[n-1];
	}
	if(i > n-1 || i < 0){
		return INT_MAX;
	}

	return arr[i] + min(solve(i+2, n), solve(i-1, n));

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
	// cout<<n;
	cout<<solve(0, n);

	


	return 0;
}