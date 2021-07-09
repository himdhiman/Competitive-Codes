#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	vector<int> v;
	int n, q, val, qr;
	cin>>n>>q;
	int mx = INT_MIN;
	int mn = INT_MAX;
	for(int i = 0; i < n; i++){
		cin>>val;
		mx = max(mx, val);
		mn = min(mn, val);
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < q; i++){
		cin>>qr;
		if(qr > mx){
			cout<<qr+n<<endl;
		}else if(qr < mn){
			cout<<qr<<endl;
		}else{
			auto lb = upper_bound(v.begin(), v.end(), qr);
			cout<<qr+lb-v.begin()<<endl;
		}

	}

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