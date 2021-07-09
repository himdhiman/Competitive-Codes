#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005;
int arr[N];
// int tree[N];

map<char, int> mapping;


// void buildTree(string s, int node, int start, int end) {
// 	if (start ==  end) {
// 		tree[node] = mapping[(s[start])];
// 		return;
// 	}
// 	int mid = (start + end) / 2;
// 	buildTree(s, 2 * node, start, mid);
// 	buildTree(s, 2 * node + 1, mid + 1, end);
// 	tree[node] = tree[2 * node] + tree[2 * node + 1];
// 	return;
// }

// int query(int node, int start, int end, int l, int r) {
// 	if (r < start || l > end) {
// 		return 0;
// 	}
// 	if (l <= start and r >= end) {
// 		return tree[node];
// 	}
// 	int mid = (start + end) / 2;
// 	int left = query(2 * node, start, mid, l, r);
// 	int right = query(2 * node + 1, mid + 1, end, l, r);
// 	return left + right;
// }

void solve() {
	for (int i = 0; i < 26; i++) {
		mapping.insert({(char)('a' + i), i + 1});
	}
	int n, q, x, y;
	cin >> n >> q;
	string s;
	cin >> s;
	// s = "#" + s;
	// memset(tree, 0, sizeof tree);
	// buildTree(s, 1, 1, n);
	arr[0] = 0;
	for (int i = 0; i < n; i++) {
		arr[i + 1] = arr[i] + mapping[s[i]];
	}

	for (int i = 0; i < q; i++) {
		cin >> x >> y;
		cout << arr[y] - arr[x - 1] << endl;
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
	t = 1;
	// cin >> t;
	while (t--) solve();




	return 0;
}