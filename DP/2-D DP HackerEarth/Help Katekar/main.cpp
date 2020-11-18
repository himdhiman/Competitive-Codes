#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1000005;
int freq[N] = {0};
int precomp[N] = {0};

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	int arr[1001] = {0};
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		freq[arr[i]]++;
	}
	int dp[1001];
	memset(dp, 1, sizeof dp);
	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j] and freq[arr[i]] > freq[arr[j]]){
				if(dp[i] == 0 and dp[j] == 0){
					dp[i] = 1 + dp[j];
					precomp[i] = max(dp[i], precomp[i]);
				}else{

				}
			}
		}
	}
	


	return 0;
}