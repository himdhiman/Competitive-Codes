#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 10000000;
bitset<N> sieve;
int arr[20];


void Sieve(){
	sieve[0] = sieve[1] = 1;
	for(int i = 2; i < N; i++){
		if(sieve[i] == 0){
			for(int j = i*i; j < N; j += i){
				sieve[j] = 1;
			}
		}
	}
}

bool isPrime(int i, int j){
	int num = 0;
	for(int k = 0; k <= j; k++){
		num += (arr[k]*10);
	}
	num /= 10;
	if(sieve[num] == 0){
		return true;
	}else{
		return false;
	}
}

bool solve(int i, int j, bool state){
	if(i == j){
		if(state == true){
			return true;
		}else{
			return false;
		}
	}
	if(isPrime(i, j)){
		if(state == true){
			return true;
		}else{
			return false;
		}
	}

	return solve(i, j-1, !state) and solve(i+1, j-1, !state);

	
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	Sieve();
	int t;
	cin>>t;
	string s;
	while(t--){
		int n;
		cin>>n;
		s = to_string(n);
		for(int i = 0; i < s.length(); i++){
			int val = s[i]-'0';
			arr[i] = val;
		}
		// for(int i = 0; i < s.length(); cout<<arr[i++]);
		// cout<<endl;
		if(solve(0, s.length()-1, true)){
			cout<<"Bob"<<endl;
		}else{
			cout<<"Alice"<<endl;
		}
	}

	


	return 0;
}