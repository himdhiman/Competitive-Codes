#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}; 
int arr[N];
int VISITED_ALL;
int dp[1<<16][51];

int solve(int mask, int n, int cnt){
	if(cnt == n || mask == VISITED_ALL){
		return 0;
	}
	if(dp[mask][cnt] != -1){
		return dp[mask][cnt];
	}
	if(arr[cnt] == 1){
		return dp[mask][cnt] = 1 + solve(mask, n, cnt+1);
	}
	int temp = mask;
	bool state = false;
	for(int i = 0; i < primes.size(); i++){
		if((arr[cnt] % primes[i]) == 0){
			if((temp&(1<<i))){
				return dp[mask][cnt] = solve(mask, n, cnt+1);
			}else{
				temp = (temp|(1<<i));
			}
		}
	}
	// max of include and exclude
	return dp[mask][cnt] = max(1 + solve(temp, n, cnt+1), solve(mask, n, cnt+1));	
}




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		memset(dp, -1, sizeof dp);
		VISITED_ALL = (1<<n)-1;
		cout<<solve(0, n, 0)<<endl;
	}
	


	return 0;
}