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
		int D, d, a, b, c;
		cin>>D>>d>>a>>b>>c;
		int dist = D*d;
		if(dist < 10){
			cout<<0<<endl;
		}else{
			if(dist >= 42){
				cout<<c<<endl;
			}else if(dist >= 21){
				cout<<b<<endl;
			}else{
				cout<<a<<endl;
			}
		}

	}


	return 0;
}