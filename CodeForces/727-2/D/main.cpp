#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

void solve() {
	int n, a, b;
	cin >> n;
	vector<pair<int, int> > arr;
	int res = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr.push_back({a, b});
		res += 2 * a;
	}
	sort(arr.begin(), arr.end(), comp);
	reverse(arr.begin(), arr.end());
	int curr = 0;
	int start = 0, end = n - 1;
	while (start <= end) {
		int temp = arr[end].second;
		if (start == end) {
			int temp1 = arr[start].first;
			int temp2 = max((int)0, arr[start].second - curr);
			temp1 = max((int)0, temp1 - temp2);
			res -= temp1;
			break;
		}
		else if (curr >= temp) {
			curr += arr[end].first;
			res -= arr[end].first;
			end--;
		}
		else if (curr + arr[start].first <= arr[end].second) {
			curr += arr[start].first;
			arr[start].first = 0;
			start++;
		}
		else {
			int temp2 = arr[end].second - curr;
			curr += temp2;
			curr += arr[end].first;
			arr[start].first -= temp2;;
			res -= arr[end].first;
			end--;
		}
	}
	cout << res << endl;
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