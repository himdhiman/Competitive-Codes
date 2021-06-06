#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 20000005;
int arr[N];

int sieve[N] = {0};

void Sieve(){
	for(int i = 2; i*i < N; i++){
		if(sieve[i] == 0){
			for(int j = i*i; j < N; j+=i){
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
	int cnt = 0;
	for(int i = 2; i < N; i++){
		if(sieve[i] == 0){
			cnt++;
		}
		arr[i] = cnt;
	}
	// cout<<arr[20]-arr[10];
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n == 2){
			cout<<1<<endl;
			continue;
		}
		if(n == 3 || n == 4 || n == 6){
			cout<<2<<endl;
			continue;
		}
		if(n == 7){
			cout<<3<<endl;
		}
		if(n == 5){
			cout<<4<<endl;
		}
		int ans = 1;
		int start = (n/2);
		if(start%2 == 0){
			start--;
		}
		// for(int i = start; i <= n; i+=2){
		// 	if(sieve[i] == 0 and i*2 > n){
		// 		// cout<<i<<endl;
		// 		ans++;
		// 	}
		// }

		// cout<<endl;
		cout<<ans + arr[n]-arr[n/2]<<endl;
	}
	


	return 0;
}