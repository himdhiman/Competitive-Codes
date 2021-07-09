#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;


void solve() {
	int n, a, b;
	cin >> n;
	vector<int> A, B;
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		A.push_back(a);
	}
	for (int i = 0; i < n; i++) {
		cin >> b;
		B.push_back(b);
	}
	for (int i = 0; i < n; i++) {
		m[A[i]] = B[i];
	}
	bool flag = true;
	int ans = 0;
	vector<int> visited(n + 1, 0);
	int tme = 0;
	for (auto x : m) {
		int curr = x.first;
		if (visited[curr] == 0) {
			ans++;
			visited[curr] = 1;
			curr = m[curr];
			while (visited[curr] != 1) {
				visited[curr] = 1;
				curr = m[curr];
			}
		}
		int temp = 1;
		for (int i = 1; i <= n; i++) {
			temp = temp & visited[i];
		}
		// cout << endl;
		// for (int i = 1; i <= n; i++) {
		// cout << visited[i] << " ";
		// }
		if (temp == 1 and tme == 0) {
			flag = false;
			break;
		} else if (temp == 1) {
			break;
		}
		tme++;
	}
	if (!flag) {
		ans--;
	}
	cout << (2 * ans + 2 ) % MOD << endl;


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