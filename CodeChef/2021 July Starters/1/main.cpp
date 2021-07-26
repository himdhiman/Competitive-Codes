#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve() {
	int a1, b1, c1, a2, b2, c2;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	int ans1 = 0, ans2 = 0;
	if (a1 > a2) {
		ans1++;
	} else {
		ans2++;
	}
	if (b1 > b2) {
		ans1++;
	} else {
		ans2++;
	}
	if (c1 > c2) {
		ans1++;
	} else {
		ans2++;
	}

	if (ans1 > ans2) {
		cout << 'A' << endl;
	} else {
		cout << 'B' << endl;
	}

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