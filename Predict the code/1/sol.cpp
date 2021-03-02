#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int N = 100005, var = 1;
	vector<int> v(N+1, 25);
	for(int i = 1; i <= N; i++){
		var *= i;
		v[i] = v[i-1] + i*var;
	}
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n < 0 or n >= 20){
            cout<<"INVALID"<<endl;
        }else{
            cout<<v[n]<<endl;            
        }
	}

	return 0;
}