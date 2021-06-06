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
		int a, b, c, d, x;
		cin>>a>>b>>c>>d>>x;
		int steps = abs(c-a) + abs(d-b);
		if(x < steps){
			cout<<"NO"<<endl;
		}else if(x == steps){
			cout<<"YES"<<endl;
		}else{
			if((x-steps)&1){
				cout<<"NO"<<endl;
			}else{
				cout<<"YES"<<endl;
			}
		}
	}

	


	return 0;
}