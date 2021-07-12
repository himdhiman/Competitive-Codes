#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve() {
	string s;
	cin >> s;
	vector<int> visited(26, 0);
	for (int i = 0; i < s.length(); i++) {
		visited[s[i] - 'a']++;
	}
	if (s.length() > 26) {
		cout << "No" << endl;
		return;
	}
	for (int i = 0; i < s.length(); i++) {
		if (visited[i] != 1) {
			cout << "No" << endl;
			return;
		}
	}
	cout << "Yes" << endl;
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