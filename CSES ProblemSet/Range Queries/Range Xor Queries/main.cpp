#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005;
int prefix[N];



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n, q, l, r, val;
	cin>>n>>q;
	prefix[0] = 0;
	for(int i = 1; i <= n; i++){
		cin>>val;
		prefix[i] = prefix[i-1]^val;
	}
	while(q--){
		cin>>l>>r;
		cout<<(prefix[r]^prefix[l-1])<<endl;
	}

	


	return 0;
}