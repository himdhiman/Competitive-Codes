#include<bits/stdc++.h>
#define int long long
#define MAX 1000000
#define MOD 1000000007
using namespace std;

int sieve[MAX] = {0};

void Solve(){
	sieve[1] = 1;
	for(int i = 2; i < MAX; i++){
		if(sieve[i] == 0){
			sieve[i] = i;
			for(int j = i*i; j < MAX; j += i){
				sieve[j] = i;
			}
		}
	}
}

void Solution(vector<int> v, unordered_map<int, int> &m){
	for(int i = 0; i < v.size(); i++){
		int curr = v[i];
		while(sieve[curr] != curr){
			m[sieve[curr]]++;
			curr = curr/sieve[curr];
		}
		m[sieve[curr]]++;
	}
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	Solve();
	// for(int i = 0; i < 20; i++){
	// 	cout<<sieve[i]<<" ";
	// }

	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin>>v[i];
		}
		unordered_map<int, int> m;
		Solution(v, m);
		int ans = 1;
		for(auto x : m){
			ans *= (x.second+1)%MOD;
		}
		cout<<ans<<endl;
	}
	return 0;
}