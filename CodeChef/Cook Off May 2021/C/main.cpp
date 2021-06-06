#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 10;
int result[N][N];

int solve(int x, int y){
	y = y+x-1;
	return (y*(y-1))/2 + x;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;	
	while(t--){
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		int ans = 0;
		for(int i = x1; i <= x2; i++){
			ans += solve(i, y1);
		}
		for(int i = y1+1; i <= y2; i++){
			ans += solve(x2, i);
		}
		cout<<ans<<endl;
	}
	
	


	return 0;
}