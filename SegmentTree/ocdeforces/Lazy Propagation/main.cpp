#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1e5;
int n;
int t[2 * N], d[N];

void apply(int p, int value) {
	t[p] += value;
	if (p < n) d[p] += value;
}

void build(int p) {
	while (p > 1) p >>= 1, t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
}

void push(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
			apply(i << 1, d[i]);
			apply(i << 1 | 1, d[i]);
			d[i] = 0;
		}
	}
}

void inc(int l, int r, int value) {
	l += n, r += n;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) apply(l++, value);
		if (r & 1) apply(--r, value);
	}
	build(l0);
	build(r0 - 1);
}

int query(int l, int r) {
	l += n, r += n;
	push(l);
	push(r - 1);
	int res = -2e9;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = max(res, t[l++]);
		if (r & 1) res = max(t[--r], res);
	}
	return res;
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