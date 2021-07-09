#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;


int32_t main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		int k, a, b, c;
		cin >> k >> a >> b >> c;
		cout << min((a - k % a) % a, min((b - k % b) % b, (c - k % c) % c)) << endl;
		// cout<<ans<<endl;
	}
	return 0;
}