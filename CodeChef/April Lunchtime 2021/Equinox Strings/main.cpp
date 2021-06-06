#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

const int N = 100005;
int arr[N];

int solve(int n){

	return 0;
}

set<char> s = {'E', 'Q', 'U', 'I', 'N', 'O', 'X'};


int32_t main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif 

	int t;
	cin>>t;
	while(t--){
		int n, a, b;
		string str;
		cin>>n>>a>>b;
		int an = 0, sa = 0;
		for(int i = 0; i < n; i++){
			cin>>str;
			if(s.find(str[0]) != s.end()){
				sa += a;
			}else{
				an += b; 
			}
		}
		if(sa > an){
			cout<<"SARTHAK"<<endl;
		}else if(sa == an){
			cout<<"DRAW"<<endl;
		}else{
			cout<<"ANURADHA"<<endl;
		}
	}

	


	return 0;
}