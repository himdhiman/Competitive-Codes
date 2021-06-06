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
		int cntneg = 0;
		int cntz = 0;
		int index = 0;
		for(int i = 0; i < n; i++){
			cin>>arr[i];
			if(arr[i] <= 0){
				index = i;
				cntneg++;
			}
			if(arr[i] == 0){
				cntz++;
			}
		}


		if(index == n-1){
			cout<<cntneg<<endl;
		}else{
			if(index < n-1 and cntz == 0){
				cout<<cntneg+1<<endl;
			}else{
				cout<<cntneg<<endl;
			}
		}
	}

	


	return 0;
}