#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	string s;
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int n = s.length();
		vector<int> par(n, -1);
		set<int> res;
		for(int i = 0; i < n; i++){
			if(s[i] == '1'){
				if(i == 0){
					par[i] = i;
				}else if(s[i-1] == '0'){
					par[i] = i;
				}else{
					par[i] = par[i-1];
				}
				if(par[i] != -1){
					res.insert(par[i]);
				}
			}
		}
		cout<<res.size()<<endl;
	}


	


	return 0;
}