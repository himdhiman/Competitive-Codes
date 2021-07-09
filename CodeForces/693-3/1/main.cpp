#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	int a, b, n;
	cin>>a>>b>>n;
	if(n == 1){
		cout<<"YES"<<endl;
		return;
	}
	if(a%2 != 0 and b%2 != 0 and n != 1){
		cout<<"NO"<<endl;
		return;
	}
	int ans = 1;
	while(a%2 == 0){
		a = a/2;
		ans *= 2;
	}
	while(b%2 == 0){
		b = b/2;
		ans *= 2;
	}
	if(ans >= n){
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;

	return;

}



int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	// t = 1;
	cin>>t;
	while(t--) solve();

	


	return 0;
}