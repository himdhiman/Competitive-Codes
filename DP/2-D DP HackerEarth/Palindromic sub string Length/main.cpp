#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10005;

int sieve[N] = {0};

void setSieve(){
	sieve[1] = 1;
	for(int i = 2; i < N; i++){
		if(sieve[i] == 0){
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

	setSieve();
	int t;
	cin>>t;
	string s;
	getline(cin, s);
	while(t--){
		getline(cin, s);
		int max_len = 1;
		for(int i = 1; i < s.length(); i++){
			int l, r;
			//for odd length
			l = i;
			r = i;
			while(l >= 0 and r <= s.length()-1 and s[l] == s[r]){
				r++;
				l--;
			}
			max_len = max(max_len, r-l-1);

			//for even length
			l = i-1;
			r = i;
			while(l >= 0 and r <= s.length()-1 and s[l] == s[r]){
				r++;
				l--;
			}
			max_len = max(max_len, r-l-1);
		}
		cout<<max_len<<endl;
		if(sieve[max_len] == 0){
			cout<<"PRIME"<<endl;
		}else{
			cout<<"NOT PRIME"<<endl;
		}
		// cout<<sieve[max_len]<<endl;
	}

	


	return 0;
}