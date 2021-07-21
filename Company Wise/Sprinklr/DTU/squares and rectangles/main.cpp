#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.first > b.first;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int> > v;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({x, y});
	}
	vector<int> temp;
	sort(v.begin(), v.end(), comp);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if ((temp.size() & 1)) {
			if (v[i].second >= 2) {
				temp.push_back(v[i].first * 2);
				v[i].second -= 2;
			}
		}
		if (v[i].second >= 4) {
			ans += (v[i].second / 4) * v[i].first * 4;
			v[i].second -= (v[i].second / 4) * 4;
		}
		if (v[i].second >= 2) {
			temp.push_back(v[i].first * 2);
			v[i].second -= 2;
		}
	}

	if (temp.size() % 2 != 0) {
		temp.pop_back();
	}
	for (int i = 0; i < temp.size(); i++) {
		ans += temp[i];
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