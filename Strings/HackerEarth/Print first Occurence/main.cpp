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
	while(t--){
		string s;
		cin>>s;
		vector<int> freq(26, 0);
		for(int i = 0; i < s.length(); i++){
			if(freq[s[i]-'a'] == 0){
				cout<<s[i];
				freq[s[i]-'a']++;
			}
		}
		cout<<endl;
	}

	


	return 0;
}