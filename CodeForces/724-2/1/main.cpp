#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 
	int t;
	cin>>t;
	while(t--){
		set<int> s;	
		int n, val;
		cin>>n;
		bool isNeg = false;
		for(int i = 0; i < n; i++){
			cin>>val;
			if(val < 0){
				isNeg = true;
			}
		}
		if(!isNeg){
			cout<<"Yes"<<endl;
			cout<<101<<endl;
			for(int i = 0; i < 101; i++){
				cout<<i<<" ";
			}
			cout<<endl;
		}else{
			cout<<"NO"<<endl;
		}

		

	}

	


	return 0;
}