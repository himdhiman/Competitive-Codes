#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){

	return 0;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int D, d, P, Q;
		cin>>D>>d>>P>>Q;
		int n = D/d;
		int ans1 = (n*d*(2*P + (n-1)*Q))/2;

		int rem = D%d;
		int ans2 = (P + n*Q)*rem;
		cout<<ans1 + ans2<<endl;

	}

	


	return 0;
}