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
		string s;
		cin>>n;
		cin>>s;
		int cnt1 = 0;
		bool flag = false;
		for(int i = 0; i < n; i++){
			if(s[i] == '1'){
				cnt1++;
			}
			if((cnt1/(float)(i+1)) >= 0.5){
				cout<<"YES"<<endl;
				flag = true;
				break;
			}
		}
		if(!flag){
			cout<<"NO"<<endl;
		}
	}

	


	return 0;
}