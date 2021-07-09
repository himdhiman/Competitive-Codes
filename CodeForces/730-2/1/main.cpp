#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;



int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int ans = abs(a - b);
		if (ans == 0) {
			cout << 0 << " " << 0 << endl;
		} else {
			int rem1 = (a) % ans;
			cout << ans << " " << min(ans - rem1, rem1) << endl;
		}
	}
	return 0;
}