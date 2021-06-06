#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000005;
vector<int> v(N, 1);

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
		int n, m;
		cin>>n>>m;
		int ans = 0;
		for(int i = 2; i <= n; i++){
			int temp = m%i;
			ans += v[temp];
			for(int j = temp; j <= n; j+=i){
				v[j]++;
			}
		}
		cout<<ans<<endl;
		fill(v.begin(), v.end(), 1);
	}

	


	return 0;
}