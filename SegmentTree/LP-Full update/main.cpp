#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int lazy[N];
int tree[N];

void buildTree(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	buildTree(2 * node, start, mid);
	buildTree(2 * node + 1, mid + 1, end);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
	return;
}

void update(int node, int start, int end, int l, int r, int val) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node];
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (r < start || end < l) {
		return;
	}
	if (l <= start and r >= end) {
		int temp = tree[node];
		tree[node] = val;
		if (start != end) {
			lazy[2 * node] += (val - temp);
			lazy[2 * node + 1] += (val - temp);
		}
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}

int query(int node, int start, int end, int l, int r) {
	if (lazy[node] != 0) {
		tree[node] += lazy[node];
		if (start != end) {
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (l > end  || r < start) {
		return INT_MIN;
	}
	if (l <= start and r >= end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	int left = query(2 * node, start, mid, l, r);
	int right = query(2 * node + 1, mid + 1, end, l, r);
	return max(left, right);
}



int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	buildTree(1, 1, n);
	for (int i = 1; i <= 7; i++) {
		cout << tree[i] << " ";
	}
	cout << endl;
	cout << query(1, 1, n, 1, 3) << endl;
	update(1, 1, n, 3, 4, 1);
	for (int i = 1; i <= 7; i++) {
		cout << tree[i] << " ";
	}
	cout << endl;
	cout << query(1, 1, n, 3, 3) << endl;

	// update(1, 1, n, 1, 3, -2);
	// update(1, 1, n, 2, 6, -9);
	// cout << query(1, 1, n, 6, 6) << endl;





	return 0;
}