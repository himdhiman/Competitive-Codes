#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 200005;
// int arr[N];

void solve(){
	int n, l, r, val;
	cin>>n>>l>>r;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin>>val;
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for(int i = n-1; i >= 0; i--){
		int rightBound = r-v[i];
		int lowerBound = l-v[i];
		// auto ub = upper_bound(v.begin(), v.end(), rightBound);
		// auto lb = lower_bound(v.begin(), v.end(), lowerBound);
		// ub--;
		// ans += (ub-lb+1);
		// if(lb-v.begin() <= i and ub-v.begin() >= i){
		// 	ans--;
		// }
		auto ub = upper_bound(v.begin(), v.begin()+i, rightBound);
		auto lb = lower_bound(v.begin(), v.begin()+i, lowerBound);
		ans += (ub-lb+1);

	}
	cout<<ans-n<<endl;
	// cout<<(ans/2)<<endl;
	

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