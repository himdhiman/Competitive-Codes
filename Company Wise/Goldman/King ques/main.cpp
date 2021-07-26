#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;


int build(int node, int arr[][2]) {
	if (arr[node][0] < 0 and arr[node][1] < 0) {
		return max(abs(arr[node][0]), abs(arr[node][1])) * 2;
	}
	int left;
	if (arr[node][0] > 0) {
		left = build(arr[node][0] - 1, arr);
	} else {
		left = abs(arr[node][0]);
	}

	int right;
	if (arr[node][1] > 0) {
		right = build(arr[node][1] - 1, arr);
	} else {
		right = abs(arr[node][1]);
	}

	return max(abs(left), abs(right)) * 2;

}

void solve(int n, int a[][2]) {
	int ans = build(0, a);
	string res = "";
	while (ans) {
		if (ans % 2) {
			res += '1';
		} else {
			res += '0';
		}
		ans /= 2;
	}
	reverse(res.begin(), res.end());
	cout << res << endl;
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
	// cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n][2];
		for (int i = 0; i < n; i++) {
			cin >> arr[i][0] >> arr[i][1];
		}
		solve(n, arr);
	}




	return 0;
}