#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
	int n, x, t;
	cin >> n >> x >> t;
	int temp = min(n - 1, t / x);
	if (temp == 0) {
		cout << 0 << endl;
		return;
	}
	int ans = max((int)0, temp * (temp - 1) / 2) + temp * (n - temp);
	cout << ans << endl;
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
	cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}