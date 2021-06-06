#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int mapping[7] = {11, 111, 1111, 11111, 111111, 1111111, 11111111};


int solve(int n, int i){
	if(n == 0){
		return 1;
	}
	if(i == 0 || n < 0){
		return 0;
	}
	if(mapping[i-1] > n){
		return solve(n, i-1);
	}
	int inc = solve(n-mapping[i-1], i);
	if(inc){
		return 1;
	}
	return solve(n, i-1);
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		// (solve(n, 7) == 1 ? cout<<"YES"<<endl : cout<<"NO"<<endl);
		if(solve(n, 7)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}