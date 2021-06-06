#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	for(int x = 1; x <= t; x++){
		int n, k;
		cin>>n>>k;
		string s;
		cin>>s;
		int score = 0; 
		int start = 0, end = s.length()-1;
		while(start < end){
			if(s[start++] != s[end--]){
				score++;
			}
		}
		cout<<"Case #"<<x<<": "<<abs(score - k)<<endl;
	}

	


	return 0;
}