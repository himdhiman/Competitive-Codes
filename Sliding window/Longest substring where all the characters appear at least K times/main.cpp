#include<bits/stdc++.h>
using namespace std;



int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	string s;
	cin>>s;
	int k;
	cin>>k;
	// cout<<s<<k<<endl;
	int freq[26] = {0};
	int end = 0;
	int ans = 0;
	while(end != s.length()){
		freq[s[end]-97]++;
		if(freq[s[end]-97] == k){
			int cnt = 1;
			int ptr = end-1;
			while(ptr >= 0 and freq[s[ptr]-97] == k){
				ptr--;
				cnt++;
			}
			ans = max(ans, cnt);
		}
		end++;
	}
	cout<<ans<<endl;
}