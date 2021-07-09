#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	int n, w, val;
	cin>>n>>w;
	multiset<int> m;
	for(int i = 0; i < n; i++){
		cin>>val;
		m.insert(val);
	}
	int ans = 0;
	int curr = w;
	// int temp = 5;
	while(true){
		auto ub = upper_bound(m.begin(), m.end(), curr);
		if(*(ub) > curr){
			ans++;
			curr = w;
		}
		curr -= *(lb);
		if(curr == 0){
			curr = w;
			ans++;
		}
		m.erase(lb);
		if(m.size() == 0){
			break;
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
	// cin>>t;
	solve();

	// vector<int> v = {};
	// multiset<int> m(v.begin(), v.end());
	// auto lb = *(lower_bound(m.begin(), m.end(), 2));
	// m.erase(lb);
	// for(auto x : m){
	// 	cout<<x<<" "; 
	// }
	// cout<<lb;

	


	return 0;
}