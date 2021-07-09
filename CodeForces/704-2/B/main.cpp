#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> idx(n + 1, 0);
	vector<int> visited(n + 1, 0);
	int mx = n;
	for (int i = 0; i < n; i++) {
		idx[arr[i]] = i;
	}
	vector<int> res;
	while (mx > 0) {
		for (int i = idx[mx]; i < n; i++) {
			if (visited[arr[i]] == 0) {
				res.push_back(arr[i]);
				visited[arr[i]] = 1;
			} else {
				break;
			}
		}
		int temp = mx;
		for (int j = temp; j >= 0; j--) {
			if (visited[j] == 0) {
				mx = j;
				break;
			}
		}
	}

	for (auto x : res) {
		cout << x << " ";
	}
	cout << endl;

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