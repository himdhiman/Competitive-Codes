#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int sieve[N] = {0};
vector<int> res;

void Sieve(){
	for(int i = 0; i*i < N; i++){
		sieve[i] = i;
	}
	for(int i = 2; i < N; i++){
		if(sieve[i] == i){
			for(int j = i*i; j < N; j+=i){
				sieve[j] = i;
			}
		}
	}
}

void printFactors(int x){
	while(x != 1){
		cout<<sieve[x]<<" ";
		x = x/sieve[x];
	}
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	Sieve();
	printFactors(18676);
	


	return 0;
}