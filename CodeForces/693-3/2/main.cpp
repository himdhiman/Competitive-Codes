#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	int n;
	cin>>n;
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>arr[i];
		sum += arr[i];
	}
	if(sum&1){
		cout<<"NO"<<endl;
		return;
	}
	if(n%2 == 0){
		cout<<"YES"<<endl;
		return;
	}
	for(int i = 0; i < n; i++){
		if(arr[i] == 1){
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
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