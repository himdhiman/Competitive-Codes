#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n, int k){
	sort(arr, arr+n);
	int ans = INT_MIN;
	// for(int i = 0; i < n-1;i++){
	// 	ans = max(ans, arr[i]);
	// }
	// if(k > 2){
	// 	while(k != 2){
	// 		for(int i = 0; i < n-k; i++){
	// 			int temp = arr[i + (k+1)/2];
	// 			ans = max(ans, temp);
	// 		}
	// 		k--;
	// 	}
	// }
	if(k&1){
		for(int i = k/2; i < n-(k/2); i++){
			ans = max(ans, arr[i]);
		}
		return ans;
	}else{
		for(int i = (k/2)-1; i < n-(k/2); i++){
			ans = max(ans, arr[i]);
		}
		return ans;
	}
	return ans;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, k;
	cin>>n>>k;
	for(int i = 0 ;i < n; i++){
		cin>>arr[i];
	}
	cout<<solve(n, k);


	


	return 0;
}