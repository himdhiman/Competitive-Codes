#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 200005;
int arr[N];

void solve() {
	unordered_map<int, int> m;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		m.insert({arr[i], i + 1});
	}
	int ans = 0;
	for (int ij = 3; ij < 2 * n; ij++) {
		for (int j = 1; j <= sqrt(ij); j++) {
			if (ij % j == 0 and ij != j * j) {
				if (m.find(j) != m.end() and m.find(ij / j) != m.end() and m[j] + m[ij / j] == ij) {
					ans++;
				}
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
	// t = 1;
	cin >> t;
	while (t--) solve();




	return 0;
}