#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){
	int rem = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] > i){
			rem += (arr[i]-i);
		}else{
			if(rem >= (i-arr[i])){
				rem = rem - (i-arr[i]);
			}else{
				return 0;
			}
		}
	}
	return 1;
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
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		if(solve(n)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		
	}

	


	return 0;
}