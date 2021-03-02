#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define tc ll tc; cin>>tc; for(ll number = 1 ; number <= tc ; number ++ )
#define vv(x) vector<x >

#define forn(i,n) for(ll i=0 ; i<n ; i++)
#define arr(a,n) for(ll i=0;i<n;i++){ cin>>a[i]; }

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 

    tc {
        ll n, ans=0; cin >> n;
        vv(ll) a(n); arr(a, n);
        forn(i, n) {
            if(i&1) ans += a[i]>>1;
            else ans += a[i]<<1;
        }
        cout << ans << endl;
    }
    return 0;
}
