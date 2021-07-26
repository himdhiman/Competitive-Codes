#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve() {
	string s;
	cin >> s;
	unordered_map<char, int> m;
	for (auto c : s) {
		m[c]++;
	}
	int ans = 0;
	int temp = 0;
	for (auto x : m) {
		if (x.second >= 2) {
			ans++;
		} else {
			temp++;
		}
	}
	ans += (temp / 2);
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