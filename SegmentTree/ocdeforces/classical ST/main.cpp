#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1e5;
int n;
int t[2 * N];

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int queryRange(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

void modifyRange(int l, int r, int value) {
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) t[l++] += value;
		if (r & 1) t[--r] += value;
	}
}

int query(int p) {                      // sum of path from root to child
	int res = 0;
	for (p += n; p > 0; p >>= 1) res += t[p];
	return res;
}

void push() {                       // pushes the modification to the array values
	for (int i = 1; i < n; ++i) {
		t[i << 1] += t[i];
		t[i << 1 | 1] += t[i];
		t[i] = 0;
	}
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[n + i];
	}
	build();
	// modify(0, 100);  									// --> 0 Based Indexing
	cout << queryRange(0, 3) << endl;					//  l --> included and r --> excluded  [l, r)
	// push();
	// modifyRange()
	cout << query(3) << endl;
	for (int i = 1; i < 2 * n; i++) {
		cout << t[i] << " ";
	}
	return 0;
}