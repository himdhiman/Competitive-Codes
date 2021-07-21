#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int minSteps(string S) {
	string new_str;
	int N = S.length();
	int i = 0;
	while (i < N) {

		new_str += S[i];
		int j = i;
		while (i < N && S[i] == S[j])
			++i;
	}
	return ceil((new_str.size() + 1) / 2.0);
}

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;

	if (b >= 0) {
		cout << (b + a)*n << endl;
	} else {
		cout << (a * n) + (b * minSteps(s)) << endl;
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