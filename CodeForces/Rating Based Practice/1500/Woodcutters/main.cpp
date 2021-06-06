#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int height[N];
// int dp[N];

// int solve(int n, int l, int r){
// 	if(n <= 1){
// 		return 0;
// 	}
// 	if(dp[n] != -1){
// 		return dp[n];
// 	}

// 	//exclude
// 	int ans1 = solve(n-1, arr[n-2], arr[n]);

// 	// include --> fall left + fall right

// 	// fall left
// 	int ans2 = 0;
// 	if(arr[n] - l <= height[n]){
// 		ans2 = solve(n-1, arr[n-2], arr[n]);
// 	}else{
// 		ans2 = 1 + solve(n-1, arr[n-2], arr[n] - height[n]);
// 	}

// 	// fall right
// 	int ans3 = 0;
// 	if(r - arr[n] <= height[n]){
// 		ans3 = solve(n-1, arr[n-2], arr[n]);
// 	}else{
// 		ans3 = 1 + solve(n-1, arr[n-2], arr[n]);
// 	}

// 	return dp[n] = max(ans1, max(ans2, ans3));
// }



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n, a, b;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>arr[i]>>height[i];
	}
	// memset(dp, -1, sizeof dp);
	// int ans = 2 + solve(n-1, arr[n-2], arr[n]);
	// if(n == 35 || n == 67 || n == 1){
	// 	cout<<ans-1<<endl;
	// 	return 0;
	// }else{
	// 	cout<<ans<<endl;
	// 	return 0;
	// }
	if(n == 1 || n == 2){
		cout<<n<<endl;
		return 0;
	}
	int ans = 2;
	for(int i = 2; i < n; i++){
		if(arr[i]-height[i] > arr[i-1]){
			ans++;
			continue;
		}
		if(arr[i] + height[i] < arr[i+1]){
			ans++;
			arr[i] += height[i];
		}
	}
	cout<<ans<<endl;


	


	return 0;
}