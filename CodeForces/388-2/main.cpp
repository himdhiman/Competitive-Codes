#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int n;
	cin>>n;
	if(n&1){
		int ans = (n-1)/2;
		cout<<ans<<endl;
		for(int i = 0; i < ans-1; i++){
			cout<<2<<" ";
		}
		cout<<3;
	}else{
		int ans = (n/2);
		cout<<ans<<endl;
		for(int i = 0; i < ans; i++){
			cout<<2<<" ";
		}
	}

	


	return 0;
}