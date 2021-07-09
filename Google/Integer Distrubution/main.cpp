#include<bits/stdc++.h>
#define int long long int
using namespace std;

const int N = 21;
int arr[N];

pair<int, int> dp[1500000];

pair<int, int> solve(int mask, int n) {
	if (mask == (1 << n) - 1) {
		return {0, 0};
	}
	if (dp[mask].first != -1 and dp[mask].second != -1) {
		return dp[mask];
	}
	pair<int, int> ans = {LLONG_MIN, LLONG_MAX};
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) == 0) {
			mask = mask | (1 << i);
			for (int j = 0; j < n; j++) {
				if ((mask & (1 << j)) == 0) {
					// cout << ans.second << " " << i << " " << j << endl;
					pair<int, int> temp = solve(mask | (1 << j), n);
					ans.first = max(ans.first, (arr[i] ^ arr[j]) + temp.first);
					ans.second = min(ans.second, (arr[i] ^ arr[j]) + temp.second);
				}
			}
			mask = mask & (~(1 << i));
		}
	}
	return dp[mask] = ans;
}



int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int mask = 0;
	for (int i = 0; i < 1500000; i++) {
		dp[i] = { -1, -1};
	}
	pair<int, int> ans = solve(mask, n);
	cout << ans.second << " " << ans.first << endl;
	return 0;
}