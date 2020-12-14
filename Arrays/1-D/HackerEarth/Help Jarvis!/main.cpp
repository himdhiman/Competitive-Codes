#include<bits/stdc++.h>
#define int long long
using namespace std;




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		int val;
		cin>>val;
		unordered_map<int, int> m;
		int mn = 10;
		int len = 0;
		while(val != 0){
			int rem = val%10;
			mn = min(rem, mn);
			m[rem]++;
			len++;
			val = (val-rem)/10;
		}
		bool ans = true;
		for(int i = 0; i < len; i++){
			if(m.find(mn) == m.end()){
				ans = false;
				break;
			}else{
				mn++;
			}
		}
		if(ans){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	


	return 0;
}