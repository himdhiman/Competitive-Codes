#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007

char arr[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

ll cnt, k;
string str;

void solveEven(string ans) {
	if (ans.length() == str.length()) {
		if (ans < str) {
			cout << ans << endl;
			cnt++;
			cnt = cnt % MOD;
		}

		return;
	}

	for (ll i = 0; i < k; i++) {
		string res = arr[i] + ans + arr[i];
		solveEven(res);
	}
}

void solveOdd() {
	for (ll i = 0; i < k; i++) {
		string ans = "";
		ans += arr[i];
		solveEven(ans);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll T;
	cin >> T;
	int a = 1;
	while (T--) {
		ll n;
		cin >> n >> k;
		cin >> str;

		cnt = 0;
		if (n % 2 == 0)
			solveEven("");
		else {
			solveOdd();
		}

		cout << "Case #" << a << ": " << cnt << endl;
		a++;
	}
	return 0;
}