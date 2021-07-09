#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve() {
	int n, m, i, j;
	cin >> n >> m >> i >> j;
	int dist1 = i - 1 + j - 1;
	int dist2 = n - i + m - j;
	int dist3 = i - 1 + m - j;
	int dist4 = n - i + j - 1;

	int maxDist = max(max(dist1, dist2), max(dist3, dist4));
	if (maxDist == dist1 || maxDist == dist2) {
		cout << "1 1 " << n << " " << m << endl;
	}
	else {
		cout << n << " 1 1 " << m << endl;
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