#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000001;
int arr[N] = {0};

// int solve(int n){

// 	return 0;
// }


int getSum(int l, int r){
	return ((r-l+1)*(2*l + (r-l)))/2;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, l, r;
	cin>>n;
	int temp = 0;
	while(n--){
		cin>>l>>r;
		int val = getSum(l, r);
		temp += val;
		// for(int i = l; i <= r; i++){
		// 	arr[i] = 1;
		// }
	}
	int res = getSum(1, 1000000);
	cout<<res-temp;
	// for(int i = 1; i <= 1000000; i++){
	// 	if(arr[i] == 0){
	// 		temp += i;
	// 	}
	// }
	// cout<<temp;

	// cout<<1000000-temp;
	// int l = 2;
	// int r = 10;
	// int val = ((r-l+1)*(2*l + ((r-l+1)-1)*1))/2;
	// cout<<val;
	


	return 0;
}