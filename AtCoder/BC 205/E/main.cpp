#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int Helper(int wi, int bi, int k){
	if(wi == 0 || bi == 0){
		return 1;
	}
	if(bi+k >= wi){
		return Helper(wi-1, bi, k);
	}
	return Helper(wi-1, bi, k) + Helper(wi, bi-1, k);
}

void solve(){
	int n, m, k;
	cin>>n>>m>>k;
	cout<<Helper(n, m, k);


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