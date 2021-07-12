#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

// const int N = 100005;
// int arr[N];

void solve2() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	unordered_map<int, int> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				m[arr[j]]++, m[arr[j + 1]]++;
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	// for (auto x : m) {
	// 	if ((x.second & 1)) {
	// 		cout << "NO" << endl;
	// 		return;
	// 	}
	// }
	// cout << "YES" << endl;

	for (auto x : m) {
		cout << x.first << " " << x.second << endl;
	}

	return;
}

unordered_map<int, int> m;

void merge(int arr[], int start1, int start2, int end) {
	int temp[100];
	int i = start1;
	int j = start2;
	int s1 = start1;
	int e1 = start2 - 1;
	int s2 = start2;
	int e2 = end;
	int k = 0;
	while (s1 <= e1 && s2 <= e2) {
		if (arr[s1] <= arr[s2]) {
			m[arr[s1]] += abs((s1 - i) - k);
			temp[k++] = arr[s1++];
		} else {
			m[arr[s2]] += abs(e1 - s1 + 1 + e2 - s2);
			temp[k++] = arr[s2++];
		}
	}
	while (s1 <= e1) {
		temp[k++] = arr[s1++];
	}
	while (s2 <= e2) {
		temp[k++] = arr[s2++];
	}
	k = 0;
	for (int i = start1; i <= end; i++) {
		arr[i] = temp[k++];
	}
	return;
}
void mergeSort(int arr[], int start, int end) {
	if (start >= end) {
		return;
	}
	int mid = (start + end) / 2;
	mergeSort(arr, start, mid);
	mergeSort(arr, mid + 1, end);
	merge(arr, start, mid + 1, end);
	return;
}



void solve() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
	for (auto x : m) {
		cout << x.first << " " << x.second << endl;
	}
	cout << "YES" << endl;

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