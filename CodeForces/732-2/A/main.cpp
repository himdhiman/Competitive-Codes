#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (b[i] - a[i]);
	}
	if (ans == 0) {
		vector<pair<int, int> >pos, neg;
		for (int i = 0; i < n; i++) {
			int val = b[i] - a[i];
			if (val < 0) {
				neg.push_back({i, val});
			} else if (val > 0) {
				pos.push_back({i, val});
			}
		}
		vector<pair<int, int> > res;
		while (pos.size() != 0) {
			res.push_back({neg[0].first + 1, pos[0].first + 1});
			if (pos[0].second == 1) {
				pos.erase(pos.begin());
			} else {
				pos[0].second--;
			}
			if (neg[0].second == -1) {
				neg.erase(neg.begin());
			} else {
				neg[0].second++;
			}
		}
		cout << res.size() << endl;
		for (auto x : res) {
			cout << x.first << " " << x.second << endl;
		}

		return;
	}
	cout << -1 << endl;
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