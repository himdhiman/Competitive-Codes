#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int dp[5001][5001];

int solve2(int i, int sum) {
	if (sum == 0) {
		return 0;
	}
	if (dp[i][sum] != -1) {
		return dp[i][sum];
	}
	if (i > sum) {
		return INT_MAX;
	}
	return dp[i][sum] = 1 + min(solve2(i, sum - i), min(solve2(i + 1, sum - i), solve2(i + 2, sum - i)));
}

void solve() {
	int s;
	cin >> s;
	cout << solve2((int)1, s) << endl;
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

	while (t--) {
		memset(dp, -1, sizeof dp);
		solve();
	}




	return 0;
}