#include<bits/stdc++.h>
#define int long long
#define MAX 100000
using namespace std;

int sieve[MAX] = {0};
vector<int> primes;

void Solve(){
	for(int i = 2; i < MAX; i++){
		if(sieve[i] == 0){
			primes.push_back(i);
			for(int j = i*i; j < MAX; j+=i){
				sieve[j] = 1;
			}
		}
	}
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
	Solve();
	int t;
	cin>>t;
	while(t--){
		int m, n;
		cin>>m>>n;
		int segment[n-m+1];
		for(int i = 0; i < n-m+1; i++){
			segment[i] = 0;
		}
		for(auto x : primes){
			if(x*x > n){
				break;
			}
			int start = (m/x)*x;
			if(x >= m and x <= n){
				start = 2*x;
			}
			for(int i = start; i <= n; i += x){
				segment[i-m] = 1;
			}
		}
		for(int i = m; i <= n; i++){
			if(segment[i-m] == 0 and i != 1){
				cout<<i<<endl;
			}
		}
		cout<<endl;

	}





	return 0;
}