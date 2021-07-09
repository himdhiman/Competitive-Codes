#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

void solve(){
	int l, r;
	cin>>l>>r;
	int diff = r-l;
	int temp = diff;
	int n = 0;
	while(temp != 0){
		temp = (temp-(temp%10))/10;
		n++;
	}	
	cout<<pow(diff, n)<<endl;

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