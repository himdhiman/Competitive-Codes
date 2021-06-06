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
		vector<int> v(n);
		for(int i = 0; i < n; i++){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		int temp = 0;
		bool flag = false;
		for(int i = 0; i < n; i++){
			if(v[i] > i+1){
				flag = true;
				break;
			}
			temp += (i-v[i]+1);
		}
		if(flag){
			cout<<"Second"<<endl;
		}else{
			if(temp&1){
				cout<<"First"<<endl;
			}else{
				cout<<"Second"<<endl;
			}
		}


	}
	return 0;
}