#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	if(n&1){
		cout<<9<<" "<<(n-9);
	}else{
		cout<<4<<" "<<(n-4);
	}

	return 0;
}
