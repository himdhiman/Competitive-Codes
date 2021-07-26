#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve() {
	int x, y;
	cin >> x >> y;
	int diff = 6 - (x + y);
	if (diff <= 0) {
		cout << 0 << endl;
		return;
	}
	double ans = diff / 6.0;
	cout << fixed << setprecision(7) << ans << endl;
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