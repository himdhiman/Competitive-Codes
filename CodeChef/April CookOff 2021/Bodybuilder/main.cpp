#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int A[N];
int B[N];

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
		int n, r;
		cin>>n>>r;
		for(int i = 0; i < n; i++){
			cin>>A[i];
		}
		for(int i = 0; i < n; i++){
			cin>>B[i];
		}
		int ans = B[0];
		int x = B[0];
		for(int i = 1; i < n; i++){
			int diff = r*(A[i]-A[i-1]);
			if(x-diff <= 0){
				x = 0;
			}else{
				x = x-diff;
			}
			// x -= max((int)0, r*(A[i]-A[i-1]));
			x += B[i];
			ans = max(ans, x);
		}
		cout<<ans<<endl;
	}

	


	return 0;
}