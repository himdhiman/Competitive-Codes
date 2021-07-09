#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 200005;
int arr[N];

void solve(){
	int n;
	cin>>n;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		sum += arr[i];
	}
	if(sum % n != 0){
		cout<<-1<<endl;
		return;
	}
	int val = sum/n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] > val){
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