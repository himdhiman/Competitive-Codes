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
		int n, k;
		cin>>n>>k;
		bool flag = false;
		int mn = INT_MIN;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			mn = max(mn, arr[i]);
			if(arr[i] > 0){
				flag = false or true;
			}
		}
		if(!flag){
			cout<<mn<<endl;
		}else{
			int sum = 0, csum = 0;

			for(int i = 0; i < n; i++){
				csum += arr[i];
				if(csum < 0){
					csum = 0;
				}
				if(csum > sum){
					sum = csum;
				}
			}
			cout<<sum<<endl;
		}


	}
	


	return 0;
}