#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
	int n, q, val;
	cin >> n >> q;
	vector<int> arr(n);
	int pcnt  = 0, ncnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < q; i++) {
		cin >> val;
		auto lb = lower_bound(arr.begin(), arr.end(), val);
		if (*lb == val) {
			cout << "0" << endl;
			continue;
		}
		int pos = lb - arr.begin();
		if (pos & 1) {
			cout << "Negative" << endl;
		} else {
			cout << "Positive" << endl;
		}
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
	// cin >> t;
	while (t--) solve();




	return 0;
}