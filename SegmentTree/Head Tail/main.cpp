#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int tree[4 * N];

void build(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	build(2 * node, start, mid);
	build(2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
	return;
}

int query(int node, int start, int end, int l, int r) {
	if (r < start || l > end) {
		return 0;
	}
	if (l <= start and r >= end) {
		return tree[node];
	}
	int mid = (start + end) / 2;
	int left = query(2 * node, start, mid, l, r);
	int right = query(2 * node + 1, mid + 1, end, l, r);
	return (left + right);
}

void update(int node, int start, int end, int idx) {
	if (idx < start || idx > end) {
		return;
	}
	if (start == end) {
		tree[node] = !tree[node];
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx);
	update(2 * node + 1, mid + 1, end, idx);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
	return;

}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'H') {
			arr[i + 1] = 1;
		} else {
			arr[i + 1] = 0;
		}
	}
	build(1, 1, n);
	for (int i = 1; i <= 7; i++) {
		cout << tree[i] << " ";
	}
	cout << endl;
	update(1, 1, n, 2);
	for (int i = 1; i <= 7; i++) {
		cout << tree[i] << " ";
	}
	cout << endl;


	return;
}



int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	t = 1;
	// cin >> t;
	while (t--) solve();




	return 0;
}