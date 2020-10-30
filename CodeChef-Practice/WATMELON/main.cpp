#include<bits/stdc++.h>
using namespace std;



int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif 

	int t, n;
	cin>>t;

	while(t--) {
		cin>>n;
		int arr[n];
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			sum += arr[i];
		}
		if(sum >= 0){
			cout<<"YES"<<'\n';
		}else{
			cout<<"NO"<<'\n';
		}
	}


	return 0;
}