#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi 3.1415926535897932385
#define mod 1000000007
#define db long double
#define pp(x) pair<x,x>
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tc ll tc; cin>>tc; for(ll number = 1 ; number <= tc ; number ++ )
#define vv(x) vector<x >
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof  pop_front
#define endl "\n"
#define umap unordered_map
#define pq priority_queue
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define dbg3(x,y,z) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << #z << ": " << z << endl; }
#define bp ll kkk; cin >>kkk;
#define dbgArr(a,n) cout<<"Array "<<#a<<endl; for(ll i=0 ; i<n ; i++) cout<<a[i]<<" "; cout<<endl;
#define maxE(a,n) *max_element(a,a+n);
#define minE(a,n) *min_element(a,a+n);
#define forn(i,n) for(ll i=0 ; i<n ; i++)
#define forn1(i,n) for(ll i=1 ; i<=n ; i++)
#define arr(a,n) for(ll i=0;i<n;i++){ cin>>a[i]; }
#define arr1(a,n) for(ll i=1;i<=n;i++){ cin>>a[i]; }
#define file freopen("inp.txt","r",stdin); freopen("outp.txt","w",stdout);
#define print cout<<"Case #"<<number<<": "
#define all(x) x.begin(), x.end()
#define trav(x, a) for(auto &x: a)
#define dbgt(a) cout<<"Array "<<#a<<endl; for(auto &it:a) cout<<it<<" "; cout<<endl;
#define modinv(x) power(x, mod-2)
ll power(ll x, ll b, ll p=1) {x %= mod; while (b > 0) {if(b&1) p = (p * x) %mod; b >>= 1; x = (x*x) %mod;} return p;}
vv(ll) fact;
void fact_pre(ll n = 1100000) {fact.resize(n, 1); for(ll i=2; i<n; i++) fact[i] = (fact[i-1]*i) %mod;}
ll ncr(ll n, ll r) {if(r > n) return 0; return (fact[n] * power((fact[n-r] * fact[r]) %mod, mod-2))%mod;}
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
ll rng(ll lim, ll s=0) { uniform_int_distribution<ll> uid(s, lim - 1); return uid(rang); }
db sqr(db n) { db s=0, e=n; forn(i, 50) { db m = s + (e-s)/2; if(m*m <= n) s = m; else e = m; } return s; }

int main()
{
    FIO

    return 0;
}
