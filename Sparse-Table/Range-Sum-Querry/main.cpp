#include<bits/stdc++.h>
using namespace std;

struct SparseTable {
	int n, m;
	vector<vector<int>> mat;

	SparseTable(int _n, int _m) {
		n = _n;
		m = _m;
		mat.resize(n);
		for (int i = 0; i < n; i++) mat[i].resize(m);
	}

	void build(vector<int> arr) {
		for (int i = 0; i < n; i++) mat[i][0] = arr[i];
		for (int j = 1; j < m; j++) {
			for (int i = 0; i + (1 << j) - 1 < n; i++) {
				mat[i][j] = mat[i][j - 1] + mat[i + (1 << (j - 1))][j - 1];
			}
		}
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < m; j++) {
		// 		cout << mat[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		return;
	}

	int Query(int l, int r) {
		int sum = 0;
		for (int i = n; i >= 0; i--) {
			if (l + (1 << i) - 1 <= r) {
				sum += mat[l][i];
				l += (1 << i);
			}
		}
		return sum;
	}

};

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int m = ceil(log2(n)) + 1;
	// cout << n << " " << m << endl;
	SparseTable s(n, m);
	s.build(arr);
	cout << s.Query(0, 0);


}