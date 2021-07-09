#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	bool flag = true;
	while (n != 1) {
		while (n % a == 0) {
			n = n / a;
		}
		while (n % a != 0 and n - b > 1) {
			n = n - b;
		}
		if (n % a != 0) {
			if (flag) {
				n = n - 1;
				flag = false;
			} else {
				cout << "No" << endl;
				return;
			}
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