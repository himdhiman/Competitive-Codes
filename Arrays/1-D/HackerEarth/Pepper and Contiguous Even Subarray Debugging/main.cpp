#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(arr[i]%2 == 0){
			int temp = 1;
			for(int j = i+1; j < n; j++){
				if(arr[j]%2 == 0){
					temp++;
				}else{
					break;
				} 
			}
			ans = max(ans, temp);
		}
	}
	return ans;
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
		cout<<solve(n);
	}

	


	return 0;
}