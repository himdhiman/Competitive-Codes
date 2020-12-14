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
		int n, x;
		cin>>n>>x;
		vector<int> v(n, 0);
		for(int i = 0; i < n; i++){
			cin>>v[i];
		}
		bool isZero = false;
		for(int i = 0; i < x; i++){
			int first = v[0];
			int second = v[1];
			int curr = 2;
			while((first <= 0) and curr < n){
				first = second;
				second = v[curr];
				curr++;
			}
			int pos;
			if(first != 0 and second != 0){
				// int mn = min(first, second);
				for(int i = 31; i >= 0; i--){
					if((first>>i)&1){
						pos = i;
						break;
					}
				}
			}else if(first != 0 and second == 0){
				for(int i = 31; i >= 0; i--){
					if((first>>i)&1){
						pos = i;
						break;
					}
				}
			}else{
				isZero = true;
			}
			if(isZero){
				v[curr-2] = v[curr-2]^1;
				v[curr-1] = v[curr-1]^1;
			}else{
				v[curr-2] = v[curr-2]^(1<<pos);
				v[curr-1] = v[curr-1]^(1<<pos);
			}
			for(int i = 0; i < n; i++){
				cout<<v[i]<<" ";
			}
			cout<<endl;
		}
	}

	


	return 0;
}