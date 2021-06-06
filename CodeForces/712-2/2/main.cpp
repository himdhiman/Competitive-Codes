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
		string s1, s2;
		cin>>s1>>s2;
		if(s1 == s2){
			cout<<"YES"<<endl;
			continue;
		}
		int cnts1 = 0, cnts2 = 0;
		for(int i = 0; i < n; i++){
			if(s1[i] == '1'){
				cnts1++;
			}
			if(s2[i] == '1'){
				cnts2++;
			}
		}
		if(cnts1 != cnts2){
			cout<<"NO"<<endl;
		}else{
			if(cnts1&1){
				cout<<"NO"<<endl;
			}else{
				cout<<"YES"<<endl;
			}
		}
	}

	


	return 0;
}