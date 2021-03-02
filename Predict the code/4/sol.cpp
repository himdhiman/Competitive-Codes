#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100005;
int arr[N];

int lis(int n) {
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), arr[i]) - d.begin();
        if (d[j-1] <= arr[i] && arr[i] < d[j])
            d[j] = arr[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int32_t main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 

    int t, n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        // vector<int> dp(n+1, 1);
        // int ans = 0;
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //         if(arr[j] <= arr[i]){
        //             dp[i] = max(dp[i], dp[j]+1);
        //         }
        //         ans = max(ans, dp[i]);
        //     }
        // }
        // cout<<ans<<endl;
        cout<<lis(n)<<endl;
    }

    return 0;
}