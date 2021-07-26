#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int dp[505][505][2];

bool solve(string s, string t, int i, int j, int mode) {
	if (j >= t.length())
		return true;

	if (dp[i][j][mode] != -1)
		return dp[i][j][mode];

	char ch = t[j];
	if (mode && i + 1 < s.length() && s[i + 1] == ch) {
		bool ans1 = solve(s, t, i + 1, j + 1, 1);
		if (ans1)
			return dp[i][j][mode] = 1;
	}

	if (i - 1 >= 0 && s[i - 1] == ch) {
		bool ans2 = solve(s, t, i - 1, j + 1, 0);
		if (ans2)
			return dp[i][j][mode] = 1;
	}

	return dp[i][j][mode] = 0;
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
		string s, t;
		cin >> s >> t;

		memset(dp, -1, sizeof dp);
		bool flag = false;
		char ch = t[0];
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == ch && solve(s, t, i, 1, 1)) {
				flag = true;
				break;
			}
		}

		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}




	return 0;
}