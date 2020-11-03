#include<bits/stdc++.h>
#define int long long
using namespace std;


int solve(int n, int k, int p){
	if(n == 0 and k == 0){
		return 1;
	}
	if(n == 0 || k < 0){
		return 0;
	}
	int ans1 = 0, ans2 = 0;
	ans1 = solve(n-1, k, 0) + solve(n-1, k, 1);
	if(k > 0){
		ans2 = solve(n-1, k-1, 1);
	}
	ans2 += solve(n-1, k, 0);
	return ans1+ans2;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int s, n, k;
	cin>>s>>n>>k;

	cout<<solve(n, k, 0) + solve(n, k, 1);
	


	return 0;
}