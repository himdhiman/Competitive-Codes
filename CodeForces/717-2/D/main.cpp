#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a%b);
}

bool getLCMProduct(int start, int end){
	int ans = arr[start];
	int prd = arr[start];
	for(int i = start+1; i <= end; i++){
		ans = (ans*arr[i])/gcd(ans, arr[i]);
		prd *= arr[i];
	}
	return (ans == prd);
}


int solve(int i, int j){
	if(i > j){
		return 0;
	}
	int ans = INT_MAX;
	for(int k = i; k <= j; k++){
		if(getLCMProduct(i, k))
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, q;
	cin>>n>>q;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	


	return 0;
}