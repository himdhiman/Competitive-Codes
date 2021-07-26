#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int get(string s, string t, int i, int j) {
	if (j == 0 and i >= 0) {
		return true;
	}
	if (i <= 0) {
		return false;
	}
	if (s[i - 1] == t[j - 1]) {
		return get(s, t, i - 1, j - 1) || get(s, t, i - 2, j);
	}
	return get(s, t, i - 2, j);
}

void solve() {
	string s, t;
	cin >> s >> t;
	int i = s.length();
	int j = t.length();
	cout << get(s, t, i, j) << endl;

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