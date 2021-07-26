#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int dp[2001][2001];

int solve2(int n, int i, int j) {
	if (i == n) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	if (arr[i] == i - j + 1) {
		return dp[i][j] = max(1 + solve2(n, i + 1, j), solve2(n, i + 1, j + 1));
	}
	return dp[i][j] = max(solve2(n, i + 1, j), solve2(n, i + 1, j + 1));
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(dp, -1, sizeof dp);
	int ans = solve2(n, 0, 0);
	if (ans < k) {
		cout << -1 << endl;
		return;
	}
	// int res = INT_MAX;
	// for (int i = 0; i < 10; i++) {
	// 	for (int j = 0; j < 10; j++) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
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