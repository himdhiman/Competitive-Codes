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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			int j = i+1;
			if(j < n){
				float mx = max(arr[i], arr[j]);
				float mn = min(arr[i], arr[j]);
				float temp  = mx/mn;
				while(temp > 2){
					mn *= 2;
					temp = mx/mn;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}

	


	return 0;
}