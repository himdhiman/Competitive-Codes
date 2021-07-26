#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
	int n, m, l, cases, var;
	cin >> n >> m >> l;
	int arr[100005] = {0};
	for (int i = 0; i < m; i++) {
		cin >> cases;
		while (cases--) {
			cin >> var;
			arr[var] = i + 1;
		}
	}
	int strip[l];
	for (int i = 0; i < l; i++) {
		cin >> strip[i];
	}
	int ans = 0;
	int temp = 0;
	for (int i = 1; i < l; i++) {
		if (arr[strip[i - 1]] != arr[strip[i]]) {
			temp++;
		} else {
			ans = max(ans, temp + 1);
			temp = 0;
		}
	}
	ans = max(ans, temp + 1);
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