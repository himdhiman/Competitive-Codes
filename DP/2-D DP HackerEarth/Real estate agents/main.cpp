#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2001;
int arr[N];

int solve(int n, int k){
	if(n == 0 || k == 0){
		return 0;
	}
	int ans1 = solve(n-1, k);
	int ans2 = arr[n] + solve(n-1, k);
	for(int i = )
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, m, k;
	cin>>n>>m>>k;
	for(int i = 0; i < n; i++){
		int l, r, c;
		cin>>>l>>r>>c;
		for(int j = l; j <= r; j++){
			arr[j] = c;
		}
	}


	


	return 0;
}