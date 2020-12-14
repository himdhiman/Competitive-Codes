#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 10005;


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	string s;
	getline(cin, s);
	int cnt = s.length();
	for(int i = 1; i < s.length(); i++){
		int l, r;
		//for odd length
		l = i;
		r = i;
		while(l >= 0 and r <= s.length()-1 and s[l] == s[r]){
			r++;
			l--;
		}
		if(r-l-1 > 1){
			// cout<<r<<" "<<l<<" "<<endl;
			cnt++;
		}

		//for even length
		l = i-1;
		r = i;
		while(l >= 0 and r <= s.length()-1 and s[l] == s[r]){
			r++;
			l--;
		}
		if(r-l-1 > 1){
			// cout<<r<<" "<<l<<" "<<endl;

			cnt++;
		}
	}
	cout<<cnt; 


	


	return 0;
}