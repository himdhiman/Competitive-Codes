#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int ans = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		for(int i = 0; i < n; i++){
			if(i&1){
				ans += (arr[i]/3);
			}else{
				ans += arr[i]*2;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}