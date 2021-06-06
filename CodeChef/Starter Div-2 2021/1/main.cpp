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
		int m, x, d;
		cin>>m>>x>>d;
		int ans1 = m*x;
		int ans2 = m+d;
		cout<<min(ans1, ans2)<<endl;
	}

	


	return 0;
}