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
		int n, m;
		cin>>n>>m;
		string s;
		cin>>s;
		vector<int> marked(n, 0);
		while(m--){
			fill(marked.begin(), marked.end(), 0);
			for(int i = 0; i < n; i++){
				if(i == 0){
					if(s[1] == '1'){
						marked[0] = 1;
					}
				}else if(i == n-1){
					if(s[i-2] == '1'){
						marked[n-1] = 1;
					}
				}else{
					if((s[i-1] == '1' and s[i+1] != '1') or (s[i-1] != '1' and s[i+1] == '1')){
						marked[i] = 1;
					}
				}
			}
			for(int i = 0; i < n; i++){
				if(marked[i] == 1){
					s[i] = '1';
				}
			}
			// cout<<s<<endl;
		}
		cout<<s<<endl;
		// int start = 0;
		// for(int i = 0; i < n; i++){
		// 	if(s[i] == '1'){
		// 		start = i;
		// 		break;
		// 	}
		// }
		// int cnt = m;
		// for(int i = start-1; i >= 0 and cnt > 0; i--){
		// 	s[i] = '1';
		// 	cnt--;
		// }
		// int end = 0;
		// for(int i = n-1; i >= 0; i--){
		// 	if(s[i] == '1'){
		// 		end = i;
		// 		break;
		// 	}
		// }
		// cnt = m;
		// for(int i = end+1; i < n and cnt > 0; i++){
		// 	s[i] = '1';
		// 	cnt--;
		// }
		// vector<int> upadte;
		// for(int i = start+1; i < end; i++){
		// 	if(s[i] == '0' and s[i-1] == '1' and s[i+1] == '1'){
		// 		continue;
		// 	}else{
		// 		upadte.push_back(i);
		// 	}
		// }
		// for(auto x : upadte){
		// 	s[x] = '1';
		// }
		// for(int i = 0; i < n-2; i++){
		// 	if(s[i] == '1' and s[i+2] != '1'){
		// 		for(int j = 0; j < m and (i+j+1 < n); j++){
		// 			s[i+j+1] = '1';
		// 			i = i+j+1;
		// 		}
		// 	}
		// }
		// for(int i = 0; i < m; i++){
		// 	if(s[i] == '1'){
		// 		for(int j = 0; j < m; j++)
		// 	}
		// }
		// cout<<s<<endl;
	}

	


	return 0;
}