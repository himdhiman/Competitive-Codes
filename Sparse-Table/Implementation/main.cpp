#include<bits/stdc++.h>
using namespace std;

struct SparseTable{
	vector<vector<int> > mat;
	vector<int> p2;
	int n, m;

	SparseTable(int _n, int _m){
		n = _n;
		m = _m;
		mat.resize(n);
		p2.resize(n+1);
		for(int i = 0; i < n; i++) mat[i].resize(m);
		for(int i = 1; i <= n; i++) p2[i] = p2[i/2] + 1;
	}

	void build(vector<int> arr){
		for(int i = 0; i < n; i++) mat[i][0] = arr[i];
		for(int j = 1; j < m; j++){
			for(int i = 0; i + (1 << j) <= n; i++){
				mat[i][j] = max(mat[i][j-1], mat[i + (1 << (j-1))][j-1]);
			}
		}
		return;
	}

	int Query(int l, int r){
		int pw = p2[r-l];
		return max(mat[l][pw], mat[r-(1<<pw)+1][pw]);
	}
};

int main(){

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
	int m = ceil(log2(n)+1);
	SparseTable s(n, m);
	s.build(arr);
	cout<<s.Query(1, 4);


}