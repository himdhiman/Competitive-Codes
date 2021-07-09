#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve() {
	int n;
	cin >> n;
	double ans = 1.08 * n;
	int temp = floor(ans);
	if (temp < 206) {
		cout << "Yay!" << endl;
		return;
	}
	if (temp == 206) {
		cout << "so-so" << endl;
		return;
	}
	cout << ":(" << endl;
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