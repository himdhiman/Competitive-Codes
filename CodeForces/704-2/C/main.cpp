#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int result(string s, int l1, string t, int l2) {
	if (l2 == 0) {
		return 1;
	}
	if (l1 == 0) {
		return 0;
	}
	if (s[l1 - 1] != t[l2 - 1]) {
		return result(s, l1 - 1, t, l2);
	}
	return result(s, l1 - 1, t, l2 - 1) + result(s, l1 - 1, t, l2);
}


void solve() {
	string s, t;
	int n, m;
	cin >> n >> m;
	cin >> s >> t;
	cout << result(s, n, t, m) << endl;

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
	t = 1;
	// cin>>t;
	while (t--) solve();




	return 0;
}