#include<bits/stdc++.h>
#define int long long
using namespace std;

bool Solve(vector<int> v, int i, int n, int s){
	if(s == 0 and i > 0){
		return true;
	}
	if(n == 0){
		return false;
	}
	return Solve(v, i+1, n-1, s+v[n-1]) || Solve(v, i, n-1, s);
}



int32_t main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i){
			cin>>v[i];
		}
		int ans = Solve(v, 0, n, 0);
		if(ans){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}




	return 0;
}