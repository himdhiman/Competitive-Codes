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
		int xa, xb, Xa, Xb;
		cin>>xa>>xb>>Xa>>Xb;
		int ans1 = 0;
		if(Xa%xa == 0){
			ans1 = Xa/xa;
		}else{
			ans1 = 1 + Xa/xa;
		}
		int ans2 = 0;
		if(Xb%xb == 0){
			ans2 = Xb/xb;
		}else{
			ans2 = 1 + Xb/xb;
		}
		cout<<ans1+ans2<<endl;
	}

	


	return 0;
}