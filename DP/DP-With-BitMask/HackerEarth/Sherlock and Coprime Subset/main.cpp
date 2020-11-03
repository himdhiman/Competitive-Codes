#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;
int arr[N];
int ALL_VISITED;

int solve(int mask, int n, int i){
	if(mask == ALL_VISITED || i == n){
		return 0;
	}
	int q = solve(mask, n, i+1);	
	int ans = INT_MIN;
	for(int j = 0; j < n; j++){
		if((mask&(1<<j)) == 0){
			if(__gcd(arr[i], arr[j]) == 1){
				int temp = 1 + solve(mask|(1<<j), n, i+1);
				ans = max(ans, max(temp, q));
			}
		}
	}
	return ans;
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
		ALL_VISITED = (1<<n)-1;
		cout<<solve(0, n, 0);
	}
	


	return 0;
}