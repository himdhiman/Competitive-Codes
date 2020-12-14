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
	vector<int> v(n, 0);
	int cnt = 1;
	for(int i = 0; i < n; i++){
		cin>>v[i];
		if(i > 0){
			if(v[i] < v[i-1]){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;

	


	return 0;
}