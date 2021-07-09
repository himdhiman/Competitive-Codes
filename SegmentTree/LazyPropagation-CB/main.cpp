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
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
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
		tree[node] += val;
		if (start != end) {
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, l, r, val);
	update(2 * node + 1, mid + 1, end, l, r, val);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
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
		return INT_MAX;
	}
	if (l <= start and r >= end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	int left = query(2 * node, start, mid, l, r);
	int right = query(2 * node + 1, mid + 1, end, l, r);
	return min(left, right);
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
	update(1, 1, n, 2, 5, 1);
	cout << query(1, 1, n, 3, 6) << endl;





	return 0;
}