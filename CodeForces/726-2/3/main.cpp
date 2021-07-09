#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 200005;
int arr[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int mn = INT_MAX;
	int index;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i + 1] - arr[i] < mn) {
			mn = arr[i + 1] - arr[i];
			index = i;
		}
	}
	cout << arr[index] << " ";

	for (int i = index + 2; i < n; i++)
		cout << arr[i] << " ";

	for (int i = 0; i < index; i++)
		cout << arr[i] << " ";

	cout << arr[index + 1] << endl;

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