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
		int n, k;
		cin>>n>>k;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		int ans = 0;
		for(int i = 0; i < k; i++){
			unordered_map<int, int> m;
			int temp = 0;
			int j = i;
			while(j < n){
				m[arr[j]]++;
				temp++;
				j += k;
			}
			int tempmx = INT_MIN;
			for(auto x : m){
				tempmx = max(tempmx, x.second);
			}
			ans += (temp-tempmx);
		}
		cout<<ans<<endl;
	}

	


	return 0;
}