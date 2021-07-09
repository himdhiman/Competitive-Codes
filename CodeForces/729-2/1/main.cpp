#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
	int n, val;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++) {
		cin >> val;
		if (val & 1) {
			cnt++;
		}
	}
	if (cnt == n) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
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
	// t = 1;
	cin >> t;
	while (t--) solve();




	return 0;
}