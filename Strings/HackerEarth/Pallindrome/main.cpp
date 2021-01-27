#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

bool check(string s){
	int start = 0, end = s.length()-1;
	while(start <= end){
		if(s[start++] != s[end--]){
			return false;
		}
	}
	return true;
}

int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		if(check(s)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		
	}

	


	return 0;
}