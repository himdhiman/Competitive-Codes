#include <bits/stdc++.h>
#define int long long int
using namespace std;

int a[100005];

int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, k, sum = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    priority_queue <int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(a[i]);
        if (!(i & 1))
            pq.pop();
        sum += a[i];
    }

    int sol = 0;
    while (!pq.empty()) {
        sol += pq.top();
        pq.pop();
    }

    cout << sol << ' ' << sum - sol << '\n';
}