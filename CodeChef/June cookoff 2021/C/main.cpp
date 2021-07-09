#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnto = 0, cntz = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			cntz++;
		} else {
			cnto++;
		}
	}
	vector<int> v;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n / i == i) {
				v.push_back(i);
			}
			else {
				v.push_back(n / i);
				v.push_back(i);
			}
		}
	}
	int ans = INT_MAX;
	for (auto x : v) {
		vector<int> freq(x);
		for (int i = 0; i < x; i++) {
			for (int j = i; j < n; j += x) {
				if (s[j] == '1') {
					freq[i]++;
				}
			}
		}
		int req = n / x;
		for (int i = 0; i < x; i++) {
			int temp = req - freq[i];
			temp += (cnto - freq[i]);
			ans = min(ans, temp);
		}
	}
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
	// t = 1;
	cin >> t;
	while (t--) solve();




	return 0;
}