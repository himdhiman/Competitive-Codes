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
		if(n < 10){
			cout<<n<<endl;
		}else{
			string res = "";
			int visited[10] = {0};
			while(n > 0){
				for(int i = 9; i >= 1; i--){
					if(n >= i and visited[i] == 0){
						res += to_string(i);
						visited[i] = 1;
						n = n - i;
					}
				}
				int check = true;
				for(int i = 1; i <= 9; i++){
					if(visited[i] == 0 and n > i){
						check = false;
						break;
					}
				}
				if(check){
					break;
				}
			}
			reverse(res.begin(), res.end());
			// unordered_map<char, int> m;
			// bool flag = false;
			// for(int i = 0; i < res.length(); i++){
			// 	m[res[i]]++;
			// 	if(m[res[i]] > 1){
			// 		flag = true;
			// 		cout<<-1<<endl;
			// 		break;
			// 	}	
			// }
			if(n != 0){
				cout<<-1<<endl;
			}else{
				cout<<res<<endl;
			}
			// if(flag == false){
			// 	cout<<res<<endl;
			// }
			// cout<<res<<endl;
		}

	}

	


	return 0;
}