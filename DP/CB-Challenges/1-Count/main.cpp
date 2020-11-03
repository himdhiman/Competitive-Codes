#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n, int k){
	int l = 0, r = 0;
	int zCount = 0;
	int max_len = 1;
	int l_index = -1, r_index = -1;
	while(r < n){
		if(arr[r] == 0){
			zCount++;
		}
		while(zCount > k){
			if(arr[l] == 1){
				l++;
			}else{
				zCount--;
				l++;
			}
		}
		if(max_len < r-l+1){
			max_len = r-l+1;
			l_index = l;
			r_index = r;
		}
		r++;
	}
	for(int i = l_index; i <= r_index; i++){
		arr[i] = 1;
	}
	return max_len;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, k;
	cin>>n>>k;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	if(k > 0){
		cout<<solve(n, k)<<endl;
	}else{
		cout<<0<<endl;
	}
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}