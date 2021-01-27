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
		int n;
		cin>>n;
		// cout<<n<<" ";
		string s;
		getline(cin, s);
		getline(cin, s);
		int cnt = 0;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == '0'){
				cnt++;
			}
		}
		if(cnt > 30){
			cout<<"No"<<endl;
		}else{
			cout<<"Yes"<<endl;
		}	
	}

	


	return 0;
}