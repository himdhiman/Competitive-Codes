#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 400005;
int arr[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	for (int i = 1; i < n - 1; i++) {
		if (arr[i] > arr[i - 1] and arr[i] > arr[i + 1]) {
			int temp = max(arr[i - 1], arr[i + 1]);
			int val = abs(arr[i] - temp);
			cnt += val;
			arr[i] -= val;
		}
	}
	if (arr[0] > arr[1]) {
		int val = abs(arr[0] - arr[1]);
		cnt += val;
		arr[0] -= val;
	}
	if (arr[n - 1] > arr[n - 2]) {
		int val = abs(arr[n - 1] - arr[n - 2]);
		cnt += val;
		arr[n - 1] -= val;
	}
	int ans = 0;
	ans += arr[0];
	for (int i = 1; i < n; i++) {
		ans += abs(arr[i] - arr[i - 1]);
	}
	ans += arr[n - 1];
	cout << ans + cnt << endl;
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