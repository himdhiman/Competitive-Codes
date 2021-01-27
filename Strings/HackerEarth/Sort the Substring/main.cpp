#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

bool cmp(char a, char b){
	return a > b;
}


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	string s;
	int t, n, m;
	cin>>t;
	while(t--){
		cin>>s;
		cin>>n>>m;
		sort(s.begin()+n, s.begin()+m+1, cmp);
		cout<<s<<endl;
	}
	


	return 0;
}