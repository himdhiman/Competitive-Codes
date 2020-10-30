#include<bits/stdc++.h>
#define int long long
#define MAX 100005
using namespace std;

int sieve[MAX] = {0};

void Solve(){
	for(int i = 2; i < MAX; i++){
		if(sieve[i] == 0){
			sieve[i] = i;
			for(int j = i*i; j < MAX; j += i){
				sieve[j] = i;
			}
		}
	}
}

void Solution(vector<int> v, vector<unordered_map<int, int> > &mv){
	for(int i = 0; i < v.size(); i++){
		int curr = v[i];
		unordered_map<int, int> m;
		while(curr != sieve[curr]){
			m[sieve[curr]]++;
			curr /= sieve[curr];
		}
		m[sieve[curr]]++;
		mv.push_back(m);
	}
}


int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 
		Solve();

		int n, q;
		cin>>n;
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin>>v[i];
		}
		vector<unordered_map<int, int> > mv;
		Solution(v, mv);
		cin>>q;
		while(q--){
			int val;
			cin>>val;
			int ans = 0;
			for(int i = 0; i < mv.size(); i++){
				if(mv[i].find(val) != mv[i].end()){
					ans++;
				}
			}
			cout<<ans<<endl;
		}






	return 0;
}