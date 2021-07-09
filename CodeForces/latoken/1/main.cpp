#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];

void solve() {
	int r, c;
	cin >> r >> c;
	char arr[r][c];
	vector<pair<int, int> > v;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != '.') {
				v.push_back({i, j});
			}
		}
	}

	char temp1[r][c];
	int rStart = 0;
	for (int i = 0; i < r; i++) {
		int cStart = rStart;
		for (int j = 0; j < c; j++) {
			if (cStart == 0) {
				temp1[i][j] = 'W';
			} else {
				temp1[i][j] = 'R';
			}
			cStart = !cStart;
		}
		rStart = !rStart;
	}
	bool next = false;
	for (auto x : v) {
		if (arr[x.first][x.second] != temp1[x.first][x.second]) {
			next = true;
			break;
		}
	}
	if (!next) {
		cout << "YES" << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << temp1[i][j];
			}

			cout << endl;
		}
		return;
	}
	rStart = 0;
	for (int i = 0; i < r; i++) {
		int cStart = rStart;
		for (int j = 0; j < c; j++) {
			if (cStart == 1) {
				temp1[i][j] = 'W';
			} else {
				temp1[i][j] = 'R';
			}
			cStart = !cStart;
		}
		rStart = !rStart;
	}
	next = false;
	for (auto x : v) {
		if (arr[x.first][x.second] != temp1[x.first][x.second]) {
			next = true;
			break;
		}
	}
	if (!next) {
		cout << "YES" << endl;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << temp1[i][j];
			}

			cout << endl;
		}
		return;
	}
	cout << "NO" << endl;






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
	// cout << t << endl;
	while (t--) solve();




	return 0;
}