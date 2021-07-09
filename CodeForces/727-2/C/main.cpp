#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 200005;
int arr[N];

void solve() {
	int n, k, x;
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	vector<pair<int, int> > ind;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i + 1] - arr[i] > x) {
			if ((arr[i + 1] - arr[i]) % x == 0) {
				ind.push_back({((arr[i + 1] - arr[i]) / (x)) - 1, i});
			} else {

				ind.push_back({(arr[i + 1] - arr[i]) / (x), i});
			}
		}
	}
	sort(ind.begin(), ind.end());
	int sz = 0;
	for (auto x : ind) {
		if (k >= x.first) {
			k -= x.first;
			sz++;
		}
	}
	cout << ind.size() - sz + 1 << endl;


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