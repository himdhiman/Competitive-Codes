#include<bits/stdc++.h>
#define int long long
#define MAX 10000000
using namespace std;

bitset<MAX> b;
vector<int> primes;

void Solve(){
	b.set();
	for(int i = 2; i < MAX; i++){
		if(b[i] == 1){
			primes.push_back(i);
			for(int j = i*i; j < MAX; j += i){
				b[j] = 0;
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
	
	int n;
	cin>>n;

	cout<<primes[n-1];




	return 0;
}