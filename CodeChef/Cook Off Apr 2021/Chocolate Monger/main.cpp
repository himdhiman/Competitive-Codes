#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){

	return 0;
}



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n, x, val;
		cin>>n>>x;
		unordered_map<int, int> m;
		for(int i = 0; i < n; i++){
			cin>>val;
			m[val]++;
		}
		int sabrina = n-x;
		if(n-x > m.size()){
			cout<<m.size()<<endl;;
		}else{
			cout<<n-x<<endl;
		}
	}

	


	return 0;
}