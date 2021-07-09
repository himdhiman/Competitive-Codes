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
		} else {
			arr[start] = val;
		}
		lazy[node] = 0;
	}

	if (r < start || end < l) {
		return;
	}
	if (l <= start and r >= end) {
		int temp = tree[node];
		tree[node] += (val - temp);
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

void update1(int node, int start, int end, int l, int r, int val) {
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
		int ad = __gcd(temp, val);
		tree[node] += (ad - temp);
		if (start != end) {
			lazy[2 * node] += (ad - temp);
			lazy[2 * node + 1] += (ad - temp);
		} else {
			arr[start] = ad;
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
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	buildTree(1, 1, n);
	for (int i = 0; i < q; i++) {
		int op;
		cin >> op;
		if (op == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		} else if (op == 2) {
			int l, r, x;
			cin >> l >> r >> x;
			update1(1, 1, n, l, r, x);
		} else if (op == 3) {
			int l, r;
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
		} else {
			int l, r;
			cin >> l >> r;
			int ans = 0;
			for (int i = l; i <= r; i++) {
				ans += arr[i];
			}
			cout << ans << endl;
		}
	}





	return 0;
}