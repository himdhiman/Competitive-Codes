#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 200005;
int A[N], B[N];
unordered_map<int, int> boy, girl;

void solve(){
	boy.clear();
	girl.clear();
	int a, b, k;
	cin>>a>>b>>k;
	for(int i = 0; i < k; i++){
		cin>>A[i];
		boy[A[i]]++;
	}
	for(int i = 0; i < k; i++){
		cin>>B[i];
		girl[B[i]]++;
	}
	// for(auto x : boy){
	// 	cout<<x.first<<" "<<x.second<<endl;
	// }
	int ans = 0;
	for(int i = 0; i < k; i++){
		ans += (k - boy[A[i]] - girl[B[i]] + 1);
	}
	cout<<ans/2<<endl;

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