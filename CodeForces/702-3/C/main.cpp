#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 1000000000005;
unordered_set<int> s;

void solve(){
	for(int i = 1; i*i*i < N; i++){
		s.insert(i*i*i);
	}
}

void func(int n){
for(int i = 1; i*i*i <= n; i++){
		if(s.count(n-i*i*i)){
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
	return;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	solve();
	while(t--){
		int n;
		cin>>n;
		func(n);		
	}

	


	return 0;
}