#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	int n;
	cin>>n;
	int ans = 0;
	ans += 10*(n%10 - 1);
	int len = 0;
	while(n != 0){
		n = (n-(n%10))/10;
		len++;
	}
	if(len == 1){
		ans++;
	}else if(len == 2){
		ans += 3;
	}else if(len == 3){
		ans += 6;
	}else{
		ans += 10;
	}
	cout<<ans<<endl;
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