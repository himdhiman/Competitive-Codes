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

	int t, am, bm, cm, tm, a, b, c;
	cin>>t;
	while(t--){
		cin>>am>>bm>>cm>>tm>>a>>b>>c;
		if(a >= am and b >= bm and c >= cm and a+b+c >= tm){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	


	return 0;
}