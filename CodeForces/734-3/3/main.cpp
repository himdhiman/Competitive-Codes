#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		m[arr[i]]++;
		if (m[arr[i]] > k) {
			m[arr[i]] = k;
		}
	}
	for (auto x : m) {
		cout << x.first << " " << x.second << endl;
	}
	for (int i = 0; i < n; i++) {
		if (m[arr[i]] > 0) {
			cout << m[arr[i]] << " ";
			m[arr[i]]--;
		} else {
			cout << 0 << " ";
		}
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
	// t = 1;
	cin >> t;
	while (t--) solve();




	return 0;
}