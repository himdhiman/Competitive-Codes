#include<bits/stdc++.h>
using namespace std;

struct SparseTable{
	int n, m;
	vector<vector<int>> mat;
	// vector<int> p2;

	SparseTable(int _n, int _m){
		n = _n;
		m = _m;
		mat.resize(n);
		// p2.resize(n+1);
		for(int i = 0; i < n; i++) mat[i].resize(m);
		// for(int i = 1; i <= n; i++) p2[i] = p2[i/2] + 1;
	}

	void build(vector<int> arr){
		for(int i = 0; i < n; i++) mat[i][0] = arr[i];
		for(int j = 1; j < m; j++){
			for(int i = 0; i + (1 << j) <= n; i++){
				mat[i][j] = min(mat[i][j-1], mat[i+(1<<(j-1))][j-1]);
			}
		} 
	}

	int Query(int l, int r){
		// int pow = p2[r-l];
		// return min(mat[l][pow], mat[r-(1<<pow)+1][pow]);
		int ans = INT_MAX;
		for(int i = m; i >= 0; i--){
			if(l + (1<<i) - 1 <= r){
				ans = min(ans, mat[l][i]);
				l += (1<<i);
			}
		}
		return ans;
	}
	
};




int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin>>arr[i];
	}

	int m = ceil(log2(n)) + 1;
	SparseTable s(n, m);
	s.build(arr);
	cout<<s.Query(3, 4);


}