#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 2005;
int arr[N];

bool comp(int a, int b){
	if(!(a&1)){
		return true;
	}
	return false;
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
		vector<int> v;
		int e = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			if(!(arr[i]&1)){
				e++;
			}else{
				v.push_back(arr[i]);
			}
		}
		// sort(arr, arr+n, comp);
		int ans = n*e - (e*(e+1))/2;
		for(int i = 1; i < v.size(); i++){
			for(int j = 0; j < i; j++){
				if(__gcd(v[j], 2*v[i]) > 1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	


	return 0;
}