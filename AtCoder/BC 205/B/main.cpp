#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N]= {0};

void solve(){
	int n, val;
	cin>>n;
	vector<int> arr(n+1, 0);
	for(int i = 0; i < n; i++){
		cin>>val;
		arr[val]++;
	}
	for(int i = 1; i <= n; i++){
		if(arr[i] == 0 || arr[i] > 1){
			cout<<"No";
			return;
		}
	}
	cout<<"Yes";
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
	t = 1;
	// cin>>t;
	while(t--) solve();

	


	return 0;
}