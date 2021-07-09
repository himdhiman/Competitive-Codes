#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];
int parent[N];

int ans = 0;

int find(int x) {
	if (parent[x] == arr[x]) {
		return arr[x];
	}
	return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	int p1 = find(a);
	int p2 = find(b);
	if (p1 != p2) {
		ans++;
		parent[b] = p1;
	}
	return;
}

void solve() {
	int n;
	cin >> n;
	ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		parent[i] = arr[i];
	}
	int start = 0, end = n - 1;
	while (start < end) {
		unite(start, end);
		start++;
		end--;
	}
	for (int i = 0; i < n; i++) {
		cout << parent[i] << " ";
	}
	cout << endl;
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
	// cin >> t;
	while (t--) solve();




	return 0;
}