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
		int g, p, val;
		cin>>g>>p;
		vector<int> v(10);
		for(int i = 0; i < 10; i++){
			cin>>v[i];
		}
		int start = 9;
		int ans = 0;
		while(start >= g){
			ans += v[start--];
		}
		if(ans%p == 0){
			cout<<(ans/p)+1<<" "<<(ans/p) + floor(v[start]/(float)p)<<endl;
		}else{
			cout<<(ans/p)<<" "<<(ans+v[start])/p<<endl;
		}
	}
	


	return 0;
}