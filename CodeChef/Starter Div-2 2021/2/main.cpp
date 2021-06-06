#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){

	return 0;
}



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
		string s;
		// bool flag = 1;
		// for(int i = 0; i < n; i++){
		// 	cin>>s;
		// 	int flagSmall = 0;
		// 	int flagLarge = 0;
		// 	for(int i = 0; i < s.length(); i++){
		// 		if(s[i] >= 'a' and s[i] <= 'm'){
		// 			if(i == s.length()-1 and (s[i] >= 'a' and s[i] <= 'm')){
		// 				flagSmall = flagSmall or 1;
		// 			}
		// 			continue;
		// 		}
		// 	}
		// 	for(int i = 0; i < s.length(); i++){
		// 		if(s[i] >= 'N' and s[i] <= 'Z'){
		// 			if(i == s.length()-1 and (s[i] >= 'N' and s[i] <= 'Z')){
		// 				flagLarge = flagLarge or 1;
		// 			}
		// 			continue;
		// 		}
		// 	}
		// 	flag = flag and (flagLarge || flagSmall);
		// }
		// if(n == 1){
		// 	cout<<"NO"<<endl;
		// }else if(flag){
		// 	cout<<"YES"<<endl;
		// }else{
		// 	cout<<"NO"<<endl;
		// }

		vector<string> small, large;
		for(int i = 0; i < n; i++){
			cin>>s;
			char first = s[0];
			if(first >= 'a' and first <= 'z'){
				int flag = 1;
				for(int j = 0; j < s.length(); j++){
					if(s[j] >= 'a' and s[j] <= 'm'){
						continue;
					}else{
						flag = 0;
						break;
					}
				}
				if(flag){
					small.push_back(s);
				}
			}else{
				int flag = 1;
				for(int j = 0; j < s.length(); j++){
					if(s[j] >= 'N' and s[j] <= 'Z'){
						continue;
					}else{
						flag = 0;
						break;
					}
				}
				if(flag){
					large.push_back(s);
				}
			}
		}
		if(small.size() + large.size() == n){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}

	


	return 0;
}