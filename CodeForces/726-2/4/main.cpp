#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int sieve[N] = {0};

bool isPrime(int n)
{
	// if (n <= 1)
	// 	return false;
	if (n <= 3)
		return true;

	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}

void solve() {
	int n;
	cin >> n;
	if (n & 1) {
		cout << "Bob" << endl;
		return;
	}
	int cnt = 0;
	while (n % 2 == 0) {
		n /= 2;
		cnt++;
	}
	if (n > 1) {
		cout << "Alice" << endl;
		return;
	} else {
		if (cnt & 1) {
			cout << "Bob" << endl;
			return;
		}
	}
	cout << "Alice" << endl;

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