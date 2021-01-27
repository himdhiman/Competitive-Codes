#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int solve(int x, int y){
	if(x == y){
		return 0;
	}
	if(x >= y){
		return x-y;
	}
	if(x <= 0){
		return 1;
	}
	if(y%2 == 0){
		return 1 + solve(x, y/2);
	}else{
		return 1 + min(solve(x, y-1), solve(x, y+1));
	}
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int x, y;
	cin>>x>>y;
	cout<<solve(x, y);


	


	return 0;
}