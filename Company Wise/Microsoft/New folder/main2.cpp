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
	int var = 0;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			flag = false;
			break;
		}
	}
	if (flag) {
		cout << 0 << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			var = i;
			break;
		}
	}
	int ans = 0;
	for (int i = n - 1; i >= var; i--) {
		if (s[i] == '0') {
			ans++;
		} else {
			ans += 2;
		}
	}
	ans--;
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
	t = 1;
	// cin>>t;
	while (t--) solve();




	return 0;
}