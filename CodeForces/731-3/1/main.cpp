#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve() {
	int n;
	cin >> n;
	cout << n << endl;
	string x, y;
	getline(cin, x);
	vector<vector<int> > v;
	vector<int> temp;
	while (!cin.eof())
	{
		cin >> x >> y;

		char c1 = cin.get();
		char c2 = cin.peek();

		if (c2 == '\n')
		{
			cout << x << y << endl;

			int val1 = 0;
			for (int i = 0; i < x.length(); i++) {
				if (x[i] != '0') {
					val1 += (x[i] - '0') * 10;
				} else {
					val1 *= 10;
				}
			}
			temp.push_back(val1 / 10);
			int val2 = 0;
			for (int i = 0; i < y.length(); i++) {
				if (y[i] != '0') {
					val2 += (y[i] - '0') * 10;
				} else {
					val2 *= 10;
				}
			}
			temp.push_back(val2 / 10);
			v.push_back(temp);
			temp.clear();
		} else {
			cout << x << y << endl;

			int val1 = 0;
			for (int i = 0; i < x.length(); i++) {
				if (x[i] != '0') {
					val1 += (x[i] - '0') * 10;
				} else {
					val1 *= 10;
				}
			}
			temp.push_back(val1 / 10);
			int val2 = 0;
			for (int i = 0; i < y.length(); i++) {
				if (y[i] != '0') {
					val2 += (y[i] - '0') * 10;
				} else {
					val2 *= 10;
				}
			}
			temp.push_back(val2 / 10);
		}
	}

	for (auto x : v) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
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