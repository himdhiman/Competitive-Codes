#include<bits/stdc++.h>
#define int long long
using namespace std;




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	string s;
	getline(cin, s);
	int n, m;
	cin>>n;
	cin>>m;
	string temp = s;
	int cnt = 0;
	while(temp != s || cnt == 0){
		temp = temp.substr(temp.length()-n, n) + temp.substr(0, temp.length()-n);
		cnt++;
		if(temp != s){
			temp = temp.substr(temp.length()-m, m) + temp.substr(0, temp.length()-m);
			cnt++;
		}
	}
	cout<<cnt;

	


	return 0;
}