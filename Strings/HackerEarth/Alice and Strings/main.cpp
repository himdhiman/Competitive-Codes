#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;




int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	string a, b;
	cin>>a>>b;
	if(a.length() != b.length()){
		cout<<"NO";
		return 0;
	}
	if(a == b){
		cout<<"YES";
		return 0;
	}
	int n = b.length();
	int val = 30;
	for(int i = 0; i < n; i++){
		int temp = b[i]-a[i];
		if(temp > val || temp < 0){
			cout<<"NO";
			return 0;
		}
		val = temp;
	}
	cout<<"YES";

	


	return 0;
}