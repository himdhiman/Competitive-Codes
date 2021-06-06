#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];
// int dp[N][3];


// int solve(string s, int n, int mask){
// 	if(mask == 3){
// 		return 1;
// 	}
// 	if(n <= 1){
// 		return 0;
// 	}
// 	if(dp[n][mask] != -1){
// 		return dp[n][mask];
// 	}
// 	int ans3 = solve(s, n-1, mask);
// 	int ans1 = 0;
// 	if(s[n-1] == 'B' and s[n-2] == 'A'){
// 		ans1 = solve(s, n-2, mask|(1 << 0));
// 	}
// 	int ans2 = 0;
// 	if(s[n-1] == 'A' and s[n-2] == 'B'){
// 		ans2 = solve(s, n-2, mask|(1 << 1));
// 	}
// 	return dp[n][mask] = ans1 || ans2 || ans3;
// }

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	string s;
	cin>>s;
	int n = s.length();
	// int mask = 0;
	// memset(dp, -1, sizeof dp);
	// if(solve(s, n, mask)){
	// 	cout<<"YES"<<endl;
	// }else{
	// 	cout<<"NO"<<endl;
	// }
	bool flag = false;
	int start = -1;
	for(int i = 0; i < n-1; i++){
		if(s[i] == 'A' and s[i+1] == 'B'){
			start = i;
			break;
		}
	}
	if(start != -1){
		for(int j = start+2; j < n-1; j++){
			if(s[j] == 'B' and s[j+1] == 'A'){
				flag = true;
				cout<<"YES"<<endl;
				break;
			}
		}
	}
	if(!flag){
		start = -1;
		for(int i = 0; i < n-1; i++){
			if(s[i] == 'B' and s[i+1] == 'A'){
				start = i;
				break;
			}
		}
		if(start != -1){
			for(int j = start+2; j < n-1; j++){
				if(s[j] == 'A' and s[j+1] == 'B'){
					flag = true;
					cout<<"YES"<<endl;
					break;
				}
			}
		}
	}
	if(!flag){
		cout<<"NO"<<endl;
	}

	


	return 0;
}