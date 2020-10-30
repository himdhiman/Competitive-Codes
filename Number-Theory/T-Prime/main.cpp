#include<bits/stdc++.h>
#define int long long
#define MAX 1000005
using namespace std;

int sieve[MAX] = {0};

void Sieve(){
	sieve[0] = 0;
	sieve[1] = 1;
	for(int i = 2; i < MAX; i++){
		if(sieve[i] == 0){
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
	// for(int i = 0; i < MAX; i++){
	// 	sieve[i] = 2;
	// }
	Sieve();
	int n;
	cin>>n;
	while(n--){
		int val;
		cin>>val;
		int ans = sqrt(val);
		bool flag = true;
		if(ans*ans == val){
			if(sieve[ans] == 0){
				cout<<"YES"<<endl;
				flag = false;
			}
		}
		if(flag){
			cout<<"NO"<<endl;
		}
	}

	return 0;
}