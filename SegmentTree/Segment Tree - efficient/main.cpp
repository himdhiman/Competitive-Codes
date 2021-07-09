#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int n;
int tree[2 * N];

void build() {
	for (int i = n - 1; i > 0; i--) {
		tree[i] = tree[2 * i] + tree[2 * i + 1];
	}
}

void modify(int p, int value) {  // set value at position p
	p += n;
	t[p] = value;
	for (; p > 1; p /= 2)
		t[p >> 1] = t[p] + t[p ^ 1];
}

void modifyRange(int l, int r, int value) {
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l & 1) t[l++] += value;
		if (r & 1) t[--r] += value;
	}
}

void push() {                                  // Push modifications to the leaf
	for (int i = 1; i < n; ++i) {
		t[i << 1] += t[i];
		t[i << 1 | 1] += t[i];
		t[i] = 0;
	}
}


int queryPoint(int p) {
	int res = 0;
	for (p += n; p > 0; p >>= 1) res += t[p];
	return res;
}

int queryRange(int l, int r) {
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tree[n + i];
	}

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
	// cin>>t;
	while (t--) solve();




	return 0;
}