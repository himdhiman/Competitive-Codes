#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];


int get(int n, int i, int k, int mxOdd, int mxEven) {
	if (k == 0) {
		return min(mxOdd, mxEven);
	}
	if (n == 0) {
		return INT_MAX;
	}
	int inc;
	if (i & 1) {
		inc = get(n - 1, i + 1, k - 1, max(mxOdd, arr[n - 1]), mxEven);
	} else {
		inc = get(n - 1, i + 1, k - 1, mxOdd, max(mxEven, arr[n - 1]));
	}

	int exc = get(n - 1, i, k, mxOdd, mxEven);
	return min(inc, exc);
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << get(n, (int)0, k, INT_MIN, INT_MIN);


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