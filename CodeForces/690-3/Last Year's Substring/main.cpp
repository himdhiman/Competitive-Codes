#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

string res = "2020";


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n;
		string s;
		cin>>n;
		getline(cin, s);
		getline(cin, s);
		int start = 0;
		int end = 4;
		for(int i = 0; i < 4; i++){
			if(s[i] == res[++start]){
			}else{
				break;
			}
		}
		if(start != end){
			for(int j = n-1; j > (n-4); j--){
				if(s[j] == res[--end]){
				}else{
					break;
				}
			}
		}
		// cout<<start<<" "<<end;
		// if(start == 3 or end == 0){
		// 	cout<<"YES"<<endl;
		// }else if(start == end || start + 1 == end){
		// 	cout<<"YES"<<endl;
		// }else{
		// 	cout<<"NO"<<endl;
		// }
		// cout<<start<<" "<<end<<endl;
		if(start >= end || start == 3 || end == 1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

	}

	


	return 0;
}