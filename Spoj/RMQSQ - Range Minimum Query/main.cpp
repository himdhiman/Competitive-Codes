#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5;
const int M = 16;
vector<vector<int> > mat(N, vector<int>(M));


void build(vector<int> arr, int n, int m){
	for(int i = 0; i < n; i++) mat[i][0] = arr[i];
	for(int j = 1; j < m; j++){
		for(int i = 0; i + (1<<j) - 1 < n; i++){
			mat[i][j] = min(mat[i][j-1], mat[i+(1<<(j-1))][j-1]);
		}
	}
	return;
}

int query(int l, int r, int n){
	int ans = INT_MAX;
	for(int i = n; i >= 0; i--){
		if ((l + (1<<i) - 1) <= r){
			ans = min(ans, mat[l][i]);
			l += (1<<i);
		}
	}
	return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, q;
	cin>>n;
	vector<int> arr(n);
	for (int i = 0; i < n; ++i){
		cin>>arr[i];
	}
	int m = ceil(log2(n)) + 1;
	build(arr, n, m);
	cin>>q;
	for(int i = 0; i < q; i++){
		int l, r;
		cin>>l>>r;
		cout<<query(l, r, n)<<endl;
	}
	return 0;
}