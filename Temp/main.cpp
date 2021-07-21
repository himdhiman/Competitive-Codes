#include<bits/stdc++.h>
#define int long long int
#define MOD 1000000007
using namespace std;

void solve() {
	string s;
	int k;
	cin >> k;
	cin >> s;
	int n = s.length();
	unordered_map<char, int> m;
	int start = 0, end = 0;
	int ans = 0;
	while (end < n) {
		if (m.size() <= k) {
			if (m.size() == k) {
				ans++;
			}
			if (m.find(s[end]) == m.end()) {
				m[s[end]]++;
				end++;
			} else {
				while (start < end) {
					m[s[start]]--;
					if (m[s[start]] == 0) {
						m.erase(m.find(s[start]));
					}
					start++;
				}
			}
		} else {
			while (start < end) {
				m[s[start]]--;
				if (m[s[start]] == 0) {
					m.erase(m.find(s[start]));
				}
				start++;
			}
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
	// cin >> t;
	t = 1;
	while (t--) solve();




	return 0;
}