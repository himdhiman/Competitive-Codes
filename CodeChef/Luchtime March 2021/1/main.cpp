#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int a, x, y;
		cin>>a>>y>>x;
		// int currDay = 0;
		int Candles = 0;
		// for(int i = 0; i < y; i++){
		// 	if(i == 0){
		// 		Candles = 1;
		// 	}else{
		// 		Candles += x;
		// 	}
		// }
		// Candles += (x-1);
		// cout<<Candles<<endl;
		if(a < y){
			cout<<1+x*a<<endl;
		}else{
			cout<<x*y<<endl;
		}
	}

	


	return 0;
}