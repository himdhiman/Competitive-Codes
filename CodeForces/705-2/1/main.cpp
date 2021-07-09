#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	int n, k;
	cin>>n>>k;
	if(n == 1 and k == 1){
		cout<<0<<endl;
		return;
	}
	vector<int> v;
	for(int i = (k+1)/2; i < k; i++){
		v.push_back(i);
	}
	for(int i = k+1; i <= n; i++){
		v.push_back(i);
	}
	cout<<v.size()<<endl;
	for(auto x : v){
		cout<<x<<" ";
	}
	cout<<endl;
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
	cin>>t;
	while(t--) solve();

	


	return 0;
}