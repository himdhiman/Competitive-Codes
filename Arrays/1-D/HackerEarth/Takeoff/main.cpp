#include<bits/stdc++.h>
#define int long long
using namespace std;




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n, p, q, r;
		cin>>n>>p>>q>>r;
		vector<int> v(n+1, 0);
		// for p;
		int i = p;
		while(i <= n){
			v[i] = 1;
			i = i+p;
		}
		// for(int i = 0; i <= n; i++){
		// 	cout<<i<<"-->"<<v[i]<<endl; 
		// }
		//for q;
		i = q;
		while(i <= n){
			if(v[i] == 0){
				v[i] = 1;
			}else if(v[i] == 1){
				v[i] = -1;
			}
			i = i+q;
		}
		i = r;
		while(i <= n){
			if(v[i] == 0){
				v[i] = 1;
			}else if(v[i] == 1){
				v[i] = -1;
			}
			i = i+r;
		}
		int ans = 0;
		for(int i = 0; i <= n; i++){
			if(v[i] == 1){
				ans++;
			}
		}
		cout<<ans<<endl;
	}

	


	return 0;
}