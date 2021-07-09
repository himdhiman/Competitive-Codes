#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 20005;
int arr[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1) {
		cout << 0 << endl;
		return;
	}
	if (n == 2) {
		if (arr[0] == arr[1]) {
			cout << -1 << endl;
			return;
		}
		cout << 0 << endl;
		return;
	}
	for (int i = 2; i < n; i += 2) {
		if (arr[i] != arr[0]) {
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 3; i < n; i += 2) {
		if (arr[1] != arr[i]) {
			cout << -1 << endl;
			return;
		}
	}
	cout << 0 << endl;
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