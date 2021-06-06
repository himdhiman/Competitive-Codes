#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

map<int, int> m;

void print(){
	int ans = 0;
	for(auto x : m){
		if(x.second > 0){
			ans = ans | (1 << x.first);
		}
	}
	cout<<ans<<endl;
	return;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		m.clear();
		int n, q;
		cin>>n>>q;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			for(int j = 0; j < 31; j++){
				if((arr[i] >> j) & 1){
					m[j]++;
				}
			}
		}
		// for(auto x : m){
		// 	cout<<x.first<<" --> "<<x.second<<endl;
		// }
		print();
		for(int i = 0; i < q; i++){
			int x, v;
			cin>>x>>v;
			int curr = arr[x-1];
			arr[x-1] = v;
			for(int j = 0; j < 31; j++){
				if((curr >> j) & 1){
					m[j]--;
				}
			}
			for(int j = 0; j < 31; j++){
				if((v >> j)&1){
					m[j]++;
				}
			}
			print();
		}
	}

	


	return 0;
}