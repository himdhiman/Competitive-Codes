#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 4000001;
bitset<N> sieve;
vector<int> primes;

void Sieve(){
	for(int i = 2; i*i < N; i++){
		if(sieve[i] == 0){
			primes.push_back(i);
			for(int j = i*i; j < N; j += i){
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

	Sieve();
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> arr(n, 0);
		for(int i = 0; i < n; i++){
			cin>>arr[i];
		}
		vector<int> out(n, 0);
		for(int i = 0; i < n; i++){
			out[i] = primes[arr[i]-1];
		}
		for(auto x : out){
			cout<<x<<" ";
		}
		cout<<endl;
	}


	


	return 0;
}