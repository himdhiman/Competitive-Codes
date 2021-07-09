#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}
	int start = -1, end = -1;
	for(int i = 0; i < n; i++){
		if(arr[i] == 1){
			start = i;
			break;
		}
	}
	for(int i = n-1; i >= 0; i--){
		if(arr[i] == 1){
			end = i;
			break;
		}
	}
	int ans = 0;
	for(int i = start; i <= end; i++){
		if(arr[i] == 0){
			ans++;
		}
	}
	cout<<ans<<endl;
	return;
}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	// t = 1;
	cin>>t;
	while(t--) solve();

	


	return 0;
}