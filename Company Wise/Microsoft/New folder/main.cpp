#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	int ans = 0;
	int i = 0;
	while (i < n and s[i] == '0') {
		i++;
	}
	if (i == n) {
		cout << 0 << endl;
		return;
	}
	for (int j = n - 1; j >= i; j--) {
		if (s[j] == '0') {
			ans++;
		} else {
			ans += 2;
		}
	}
	cout << ans - 1 << endl;
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